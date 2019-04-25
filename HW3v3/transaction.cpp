#include<iostream>
#include<string.h>
#include"transaction.h"
using namespace std;
Transaction::Transaction(char Type[],int Amount,Account &a):account(a),amount(Amount)
{
	strcpy((char*)type,Type);
	cout<<"Transaction constructed\n";
}