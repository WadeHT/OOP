all:clean main.o TriangularMatrix.o
	g++ -o main TriangularMatrix.o main.o
main.o: main.cpp
	g++ -c main.cpp
TriangularMatrix.o: TriangularMatrix.h TriangularMatrix.cpp
	g++ -c TriangularMatrix.cpp
	
clean:
	del TriangularMatrix.o main.o
