all: clean main.o HuffmanTree.o 
	g++ -o main HuffmanTree.o main.o
main.o: main.cpp
	g++ -c main.cpp
HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h 
	g++ -c HuffmanTree.cpp
clean:
	del *.o