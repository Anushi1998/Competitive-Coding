run: fast
	./Wrong.out

Compile:
	g++ -o Wrong.out Wrong.cpp

fast:
	g++ -pipe -O2 -lm -s -fomit-frame-pointer -o Wrong.out Wrong.cpp

debug:
	g++ -g -o Wrong.out Wrong.cpp
	gdb -tui Wrong.out

