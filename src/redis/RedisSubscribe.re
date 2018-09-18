open Core;
open Lwt;
open Redis_lwt.Client;

let print_value = str =>
  switch (str) {
  | `Bulk(Some(str)) => Lwt_io.printf("%s ", str)
  | `Error(str) => Lwt_io.printf("error: %s ", str)
  | `Status(str) => Lwt_io.printf("status: %s ", str)
  | `Int(i) => Lwt_io.printf("int: %d ", i)
  | _ => return ()
  };

let print_stream_value = value => {
  Lwt_list.iter_s(print_value, value);
  Lwt_io.printf("%s", "\n");
  Lwt_io.flush(Lwt_io.stdout);
  return ();
};

let subscribe_lwt = (host, port) => {
  let action =
    connect({host, port})
    >>= (
      connection => {
        subscribe(connection, ["example"]);
        connection;
      }
    )
    >>= (
      connection => {
        subscribe(connection, ["example"]);
        Lwt_stream.iter_s(print_stream_value, stream(conn));
      }
    );
  Lwt_unix.run(action);
};