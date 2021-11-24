all: main

main: main.o ChunkNetLib.o
	g++ -o main main.o ChunkNetLib.o

ChunkNetLib.o: ChunkNetLib.cpp ChunkNetLib.h
	g++ -c ChunkNetLib.cpp

main.o: main.cpp
	g++ -c main.cpp