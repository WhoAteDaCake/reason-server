open Opium.Std;

/* Callbag.(
  generateId
  |> filter(n => n mod 2 === 0)
  |> map(string_of_int)
  |> take(5)
  |> forEach(a => print_string(a))
); */

let print_param = get("/hello/:name", (req => {
  `String(param(req, "name")) |> respond'
}));

let _ = App.empty
  |> print_param
  |> App.run_command;
/* 
type person = {
  name: string;
  age: int;
}

let json_of_person { name ; age } =
  let open Ezjsonm in
  dict [ "name", (string name)
       ; "age", (int age) ]

let print_param = put "/hello/:name" begin fun req ->
  `String ("Hello " ^ param req "name") |> respond'
end

let print_person = get "/person/:name/:age" begin fun req ->
  let person = {
    name = param req "name";
    age = "age" |> param req |> int_of_string;
  } in
  `Json (person |> json_of_person) |> respond'
end

let _ =
  App.empty
  |> print_param
  |> print_person
  |> App.run_command */