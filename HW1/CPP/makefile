all: palindromes.o
	g++ palindromes.o -o palindromes.exe
palindromes.o: palindromes.cpp
	g++ -c palindromes.cpp
palindromes_d:
	g++ palindromes.cpp -g -o palindromes_d.exe
clean:
	del -f palindromes.exe palindromes.o