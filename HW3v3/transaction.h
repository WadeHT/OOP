#include<iostream>
#include<string.h>
using namespace std;
class Account;
class Transaction
{
	char type[20];
	Account &account;
	int amount;
public:
	Transaction(char[],int,Account &);
	~Transaction(){cout<<"Transaction destructed\n";}
	char *getTranType(void){return (char*)type;}
	int getamount(void){return amount;}
	Account &getRef(void){return account;}
};
