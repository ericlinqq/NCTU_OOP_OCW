all: prog clean
Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp
ex4-2.o: ex4-2.cpp
	g++ -c ex4-2.cpp
prog: Matrix.o ex4-2.o
	g++ -o prog Matrix.o ex4-2.o
clean:
	rm *.o
