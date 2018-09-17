cd src && dune build main.exe
../_build/default/src/main.exe
# bsc \
#   -I /home/august/.opam/4.06.1/lib/opium \
#   -bs-package-name reason-server \
#   -bs-package-output commonjs:./lib/js/ -c src/Index.re