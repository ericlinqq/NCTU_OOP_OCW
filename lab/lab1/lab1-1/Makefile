all: prog clean
lab1-1.o: lab1-1.cpp
	g++ -c lab1-1.cpp
lab1-1-main.o: lab1-1-main.cpp
	g++ -c lab1-1-main.cpp
prog: lab1-1.o lab1-1-main.o
	g++ -o prog lab1-1.o lab1-1-main.o
clean:
	rm *.o