/* open Opium.Std;

let print_param = get("/hello/:name", (req => {
  `String(param(req, "name")) |> respond'
})); */

let example = [1, 2, 3, 4, 5, 6];

Wonka.fromList(example)
  |> Wonka.filter(x => x mod 2 === 0)
  |> Wonka.map(x => x * 2)
  |> Wonka.forEach(x => print_endline(string_of_int(x)));
/* Belt.List.forEach(["test\n", "test2\n"], print_string); */

/* let _ = App.empty
  |> print_param
  |> App.run_command; */
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