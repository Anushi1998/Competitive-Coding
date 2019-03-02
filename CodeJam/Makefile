Fast:
	g++ -pipe -O2 -lm -s -fomit-frame-pointer -fstack-protector-all -fsanitize=address ./Code.cpp -o ./Code.out
	./Code.out <in.txt >out.txt

Slow:
	g++ ./Code.cpp -o ./Code.out
	./Code.out <in.txt >out.txt