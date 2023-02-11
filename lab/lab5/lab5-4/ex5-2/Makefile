all: prog clean
Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp
ex5-2.o: ex5-2.cpp
	g++ -c ex5-2.cpp
prog: Matrix.o ex5-2.o
	g++ -o prog Matrix.o ex5-2.o
clean:
	rm *.o