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
