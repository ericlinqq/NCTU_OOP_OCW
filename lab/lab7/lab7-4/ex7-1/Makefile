all: prog clean
Complex.o: Complex.cpp
	g++ -c Complex.cpp
ex7-1.o: ex7-1.cpp
	g++ -c ex7-1.cpp
prog: Complex.o ex7-1.o
	g++ -o prog Complex.o ex7-1.o
clean:
	rm *.o
