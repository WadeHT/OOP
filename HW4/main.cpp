#include<iostream>
#include <stdio.h>
#define WIDTH 7
#define DIV 1024
#include"bag.cpp"

#define test 1
using namespace std;
int main(void)
{
	Bag<string> Bag1, Bag2, Bag3;
	Bag1.insert("A");//A3 B3 C2 D1
	Bag1.insert("A");
	Bag1.insert("D");
	Bag1.insert("B");
	Bag1.insert("B");
	Bag1.insert("B");
	Bag1.insert("C");
	Bag1.insert("C");
	Bag1.insert("A");

	Bag2.insert("A");//A1 B2 C3 D2
	Bag2.insert("B");
	Bag2.insert("B");
	Bag2.insert("C");
	Bag2.insert("C");
	Bag2.insert("D");
	Bag2.insert("D");
	Bag2.insert("C");
	combine(Bag1, Bag2, Bag3);					//(5%)
    cout << "A: " << Bag3.count("A") << endl;	//印4
    cout << "B: " << Bag3.count("B") << endl;	//印5
    cout << "C: " << Bag3.count("C") << endl;	//印5
	cout << "D: " << Bag3.count("D") << endl;	//印3
	
	subtract(Bag1, Bag2, Bag3);					//(5%)	
    cout << "A: " << Bag3.count("A") << endl;	//印2
    cout << "B: " << Bag3.count("B") << endl;	//印1
    cout << "C: " << Bag3.count("C") << endl;	//印0
	cout << "D: " << Bag3.count("D") << endl;	//印0
	
	//combine(Bag1, Bag3, Bag1);					//(5%)
	cout << "A: " << Bag1.count("A") << endl;	//印5
    cout << "B: " << Bag1.count("B") << endl;	//印4
    cout << "C: " << Bag1.count("C") << endl;	//印2
	cout << "D: " << Bag1.count("D") << endl;	//印1
	
	subtract(Bag2, Bag1, Bag2);					//(5%)	
    cout << "A: " << Bag2.count("A") << endl;	//印0
    cout << "B: " << Bag2.count("B") << endl;	//印0
    cout << "C: " << Bag2.count("C") << endl;	//印1
	cout << "D: " << Bag2.count("D") << endl;	//印1
	
	return 0;
	
}