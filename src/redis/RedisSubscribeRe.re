open Core;

open Lwt;

module Client = Redis_lwt.Client;

let print_resp = opt =>
  switch (opt) {
  | Some(str) => Lwt_io.printf("%s ", str)
  | None => return()
  };

let print_value = str =>
  switch (str) {
  | `Bulk(Some(str)) => Lwt_io.printf("%s ", str)
  | `Error(str) => Lwt_io.printf("error: %s ", str)
  | `Status(str) => Lwt_io.printf("status: %s ", str)
  | `Int(i) => Lwt_io.printf("status: %d ", i)
  | _ => return()
  };

let print_stream_value = value => {
  Lwt_list.iter_s(print_value, value) |> ignore;
  Lwt_io.printf("%s", "\n") |> ignore;
  Lwt_io.flush(Lwt_io.stdout);
};

let subscribe_lwt = (host, port) => {
  let connection = Client.connect({host, port});
  let action =
    connection >>= (c => Client.hget(c, "example", "field2")) >>= print_resp;
  /*  let action =
      Client.connect({host, port})
      >>= (
        conn => {
          return(Client.hget(conn, "example", "field2"));
        }
      )
      >>= (conn => Lwt_stream.iter_s(print_value, conn));*/
  /*>>= (conn => Lwt_stream.iter_s(print_stream_value, Client.stream(conn)));*/
  Lwt_main.run(action);
  ();
};