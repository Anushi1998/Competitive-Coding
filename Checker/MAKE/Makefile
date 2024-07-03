Run : Compile
	../OUT/Generator.out
	../OUT/Wrong.out
	../OUT/Correct.out
	../OUT/Checker.out

Compile:
	/usr/local/Cellar/gcc/13.2.0/bin/c++-13 -std=c++20 ../CPP/Generator.cpp -o ../OUT/Generator.out
	/usr/local/Cellar/gcc/13.2.0/bin/c++-13 -std=c++20 ../CPP/Wrong.cpp -o ../OUT/Wrong.out
	/usr/local/Cellar/gcc/13.2.0/bin/c++-13 -std=c++20 ../CPP/Correct.cpp -o ../OUT/Correct.out
	/usr/local/Cellar/gcc/13.2.0/bin/c++-13 -std=c++20 ../CPP/Checker.cpp -o ../OUT/Checker.out

Compile2:
	/usr/local/Cellar/gcc/13.2.0/bin/c++-13 -std=c++20 -pipe -O2 -lm -s -fomit-frame-pointer ../CPP/Generator.cpp -o ../OUT/Generator.out
	/usr/local/Cellar/gcc/13.2.0/bin/c++-13 -std=c++20 -pipe -O2 -lm -s -fomit-frame-pointer ../CPP/Wrong.cpp -o ../OUT/Wrong.out

Check:
	../OUT/Wrong.out <../TXT/Test.txt
	../OUT/Correct.out <../TXT/Test.txt

Wrong:
	/usr/local/Cellar/gcc/13.2.0/bin/c++-13 -std=c++20 ../CPP/Wrong.cpp -o ../OUT/Wrong.out
	../OUT/Wrong.out

Debug:
	g++ -g ../CPP/Wrong.cpp -o ../OUT/Wrong.out
	gdb -tui ../OUT/Wrong.out