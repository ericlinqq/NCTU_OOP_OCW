all: prog clean
Vec.o: Vec.cpp
	g++ -c Vec.cpp
utils.o: utils.cpp
	g++ -c utils.cpp
ex5-3.o: ex5-3.cpp
	g++ -c ex5-3.cpp
prog: Vec.o utils.o ex5-3.o
	g++ -o prog Vec.o utils.o ex5-3.o -fno-elide-constructors
clean:
	rm *.o
