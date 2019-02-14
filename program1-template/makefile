all: program1

program1: program1.o Star.o Planet.o
	g++ program1.o Star.o Planet.o -o program1

program1.o: program1.cpp
	g++ program1.cpp -o program1.o -c

Star.o: Star.cpp
	g++ Star.cpp -o Star.o -c

Planet.o: Planet.cpp
	g++ Planet.cpp -o Planet.o -c


