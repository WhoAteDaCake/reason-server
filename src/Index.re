let example = [1, 2, 3, 4, 5, 6];

/* Curently forced to inject wonka as bs-native can't be compiled properly */
Wonka.fromList(example)
|> Wonka.filter(x => x mod 2 === 0)
|> Wonka.map(x => x * 2)
|> Wonka.forEach(x => print_endline(string_of_int(x)));