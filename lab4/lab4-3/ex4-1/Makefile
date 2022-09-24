all: prog clean
Complex.o: Complex.cpp
	g++ -c Complex.cpp
ex4-1.o: ex4-1.cpp
	g++ -c ex4-1.cpp
prog: Complex.o ex4-1.o
	g++ -o prog Complex.o ex4-1.o
clean:
	rm *.o
