run : Compile
	../OUT/Generator.out
	../OUT/Wrong.out
	../OUT/Correct.out
	../OUT/Checker.out

Compile:
	g++ -pipe -O2 -lm -s -fomit-frame-pointer ../CPP/Generator.cpp -o ../OUT/Generator.out
	g++ -pipe -O2 -lm -s -fomit-frame-pointer ../CPP/Wrong.cpp -o ../OUT/Wrong.out
	g++ -pipe -O2 -lm -s -fomit-frame-pointer ../CPP/Correct.cpp -o ../OUT/Correct.out
	g++ -pipe -O2 -lm -s -fomit-frame-pointer ../CPP/Checker.cpp -o ../OUT/Checker.out

check:
	../OUT/Wrong.out <../TXT/Test.txt
	../OUT/Correct.out <../TXT/Test.txt

Wrong:
	g++ -pipe -O2 -lm -s -fomit-frame-pointer ../CPP/Wrong.cpp -o ../OUT/Wrong.out
	../OUT/Wrong.out <../TXT/Test.txt

Debug:
	g++ -g ../CPP/Wrong.cpp -o ../OUT/Wrong.out
	gdb -tui ../OUT/Wrong.out