#include<iostream>
#include<string.h>
#include"account.h"
using namespace std;

bool Account::withdraw(int n)
{
	if(n<=amount)
	{
		Account AccountOfB;
		amount-=n;
		deductAmount+=n;
		strcpy((char*)&temp[transCounter].Type,"withdraw");
		temp[transCounter].howMuch=n;
		tra[transCounter++]= new Transaction((char*)"withdraw",n,*this);
		return true;
	}
	else return false;
}
bool Account::deposit(int n)
{
	Account AccountOfB;
	amount+=n;
	strcpy((char*)&temp[transCounter].Type,"deposit");
	temp[transCounter].howMuch=n;
	tra[transCounter++]=new Transaction((char*)"deposit",n,*this);
	return true;
}
bool Account::transferMoney(Account &AccountOfB, int amountToTransfer)
{
	if(amountToTransfer<=amount)
	{
		amount-=amountToTransfer;
		AccountOfB.amount+=amountToTransfer;
		accountOfB[transCounter] = AccountOfB.ID;
		strcpy((char*)&temp[transCounter].Type,"transferMoney");
		temp[transCounter].howMuch=amountToTransfer;
		tra[transCounter++]=new Transaction((char*)"transferMoney",amountToTransfer,AccountOfB);
		return true;
	}
	else return false;
}
void Account::getRecord(void)
{
	cout<<"Type: create\n";
	for(int i=0;i<transCounter;i++)cout<<"Type: "<<tra[i]->getTranType()<<" How much: "<<tra[i]->getamount()<<" To: "<<(tra[i]->getRef()).ID<<endl;
	return;
}
Account::Account(int Amount, int id):ID(id),amount(Amount),deductAmount(0),amountToTransfer(0),transCounter(0)
{
	memset(temp,0,sizeof(Transs)*100);
	memset(tra,0,sizeof(Transs)*100);
	cout<<"Account constructed\n";
}
Account::~Account(void)
{
	for(int i=0;tra[i]!=0;i++)tra[i]->~Transaction();
	cout<<"Account destructed\n";
}