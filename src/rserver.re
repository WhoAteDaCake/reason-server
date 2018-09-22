/*open Opium.Std;

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
RedisRe.subscribe("localhost", 7000);
/*App.empty |> print_person |> App.run_command;*/