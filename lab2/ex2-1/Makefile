all: prog clean
ex2-1.o: ex2-1.cpp
	g++ -c ex2-1.cpp
ex2-1-main.o: ex2-1-main.cpp
	g++ -c ex2-1-main.cpp
prog: ex2-1.o ex2-1-main.o
	g++ -o prog ex2-1.o ex2-1-main.o
clean:
	rm *.o
