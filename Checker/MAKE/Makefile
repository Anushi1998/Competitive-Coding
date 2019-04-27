Run : Compile
	../OUT/Generator.out
	../OUT/Wrong.out
	../OUT/Correct.out
	../OUT/Checker.out

Compile:
	g++ -std=c++11 -pipe -O2 -lm -fomit-frame-pointer ../CPP/Generator.cpp -o ../OUT/Generator.out
	g++ -std=c++11 -pipe -O2 -lm -fomit-frame-pointer ../CPP/Wrong.cpp -o ../OUT/Wrong.out
	g++ -std=c++11 -pipe -O2 -lm -fomit-frame-pointer ../CPP/Correct.cpp -o ../OUT/Correct.out
	g++ -std=c++11 -pipe -O2 -lm -fomit-frame-pointer ../CPP/Checker.cpp -o ../OUT/Checker.out

Check:
	../OUT/Wrong.out <../TXT/Test.txt
	../OUT/Correct.out <../TXT/Test.txt

Wrong:
	g++ -std=c++11 -pipe -O2 -lm -fomit-frame-pointer ../CPP/Wrong.cpp -o ../OUT/Wrong.out
	../OUT/Wrong.out <../TXT/Test.txt

Debug:
	g++ -g ../CPP/Wrong.cpp -o ../OUT/Wrong.out
	gdb -tui ../OUT/Wrong.out