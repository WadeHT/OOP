all: word_locator.o
	g++ word_locator.o -o word_locator.exe
word_locator.o: word_locator.cpp
	g++ -c word_locator.cpp
word_locator_d:
	g++ word_locator.cpp -g -o word_locator_d.exe
clean:
	del word_locator.o word_locator.exe word_locator_d.exe