#PROGRAM: CSCI 463 Assignment 3
#PROGRAMMER: Edgar Villafuerte
#Z-ID: Z1851501
#DATE DUE: 10/02/2020
#

CCFLAGS = -Wall -std=c++11

main: main.o hex.o memory.o 
	g++ $(CCFLAGS) -o main main.o hex.o memory.o 
main.o: main.cpp hex.h memory.h 
	g++ $(CCFLAGS) -c main.cpp

hex.o: hex.cpp hex.h
	g++ $(CCFLAGS) -c hex.cpp
memory.o: memory.cpp memory.h
	g++ $(CCFLAGS) -c memory.cpp
clean:
	-rm *.o main
