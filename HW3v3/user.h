#include<iostream>
#include<string.h>
#include"account.cpp"
using namespace std;
class User:public Account
{
	char name[100];
	int ID,transCounter;
	static int IDcounter;
	Transs trans[100];
	
public:
	
	
	User(const char Name[]);
	char *getUsername(void){return (char*)name;}
	Account &getAccount(void){return *this;}
	int getID(void){return ID;}
	void getTrans(void);
	~User(void){cout<<"User destructed\n";}
	
};
