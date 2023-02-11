all: prog clean
Complex.o: Complex.cpp
	g++ -c Complex.cpp
ex5-1.o: ex5-1.cpp
	g++ -c ex5-1.cpp
prog: Complex.o ex5-1.o
	g++ -o prog Complex.o ex5-1.o
clean:
	rm *.o