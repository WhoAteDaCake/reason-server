open Core;
open Lwt;

module Server = Opium.Std;
module Client = Redis_lwt.Client;

let resp_to_text = opt =>
  switch (opt) {
  | Some(opt) => Lwt.return(opt)
  | None => Lwt.return("None")
  };

let connection = Client.connect({host: "localhost", port: 7000});

let get_data =
  Server.get("/redis/:channel/:hash", req => {
    let channel = Server.param(req, "channel");
    let hash = Server.param(req, "hash");
    connection
    >>= (c => Client.hget(c, channel, hash))
    >>= resp_to_text
    >>= (text => Server.(`String(text) |> respond'));
  });

let _ = Server.App.empty |> get_data |> Server.App.run_command;

/*

 type person = {
   name: string,
   age: int,
 };

 let json_of_person = person =>
   Ezjsonm.(
     [("name", person.name |> string), ("age", person.age |> int)] |> dict
   );

 let print_person =
   get("/person/:name/:age", req => {
     let person = {
       name: param(req, "name"),
       age: param(req, "age") |> int_of_string,
     };
     `Json(person |> json_of_person) |> respond';
   });
 */
/*App.empty |> print_person |> App.run_command;*/