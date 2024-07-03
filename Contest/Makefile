g++ := /usr/local/Cellar/gcc/13.2.0/bin/c++-13

Slow:
	/usr/local/Cellar/gcc/13.2.0/bin/c++-13 -std=c++17 -o Wrong.out Wrong.cpp
	./Wrong.out

Run:
	./Wrong.out

Fast:
	/usr/local/Cellar/gcc/13.2.0/bin/c++-13 -std=c++20 -pipe -O2 -lm -s -fomit-frame-pointer -o Wrong.out Wrong.cpp
	./Wrong.out

Debug:
	/usr/local/Cellar/gcc/13.2.0/bin/c++-13 -std=c++20 -g -o Wrong.out Wrong.cpp
	sudo gdb -tui Wrong.out
