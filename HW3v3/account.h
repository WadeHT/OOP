#include<iostream>
#include<string.h>
#include"transaction.cpp"
using namespace std;
typedef struct
{
	char Type[20];
	int howMuch;
}Transs;
class Account
{
	int amount,deductAmount,amountToTransfer;
	int transCounter;
	int accountOfB[100];
	Transaction *tra[100];
public:
	Transs temp[100];
	const int ID;
	Account(int Amount=0, int id=-1);
	bool withdraw(int n);
	bool deposit(int n);
	bool transferMoney(Account &AccountOfB, int amountToTransfer);
	int getAmount(void){return amount;}
	void getRecord(void);
	~Account(void);
};