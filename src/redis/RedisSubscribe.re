open Core;

open Lwt;

open Redis_lwt.Client;

let print_value = str =>
  switch str {
  | `Bulk(Some(str)) => Lwt_io.printf("%s ", str)
  | `Error(str) => Lwt_io.printf("error: %s ", str)
  | `Status(str) => Lwt_io.printf("status: %s ", str)
  | `Int(i) => Lwt_io.printf("int: %d ", i)
  | _ => return()
  };

let print_stream_value = value => {
  Lwt_list.iter_s(print_value, value) |> ignore;
  Lwt_io.printf("%s", "\n") |> ignore;
  Lwt_io.flush(Lwt_io.stdout);
};

let subscribe_lwt = (host, port) => {
  let action =
    connect({host, port})
    >>= (
      conn => {
        subscribe(conn, ["example"]) |> ignore;
        return(conn);
      }
    )
    >>= (conn => Lwt_stream.iter_s(print_stream_value, stream(conn)));
  Lwt_main.run(action);
  ();
};
