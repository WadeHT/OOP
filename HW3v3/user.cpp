#include<iostream>
#include<string.h>
#include"user.h"
using namespace std;
void User::getTrans(void)
{
	memcpy(trans,temp,sizeof(Transs)*100);
	cout<<"Type: create\n";
	for(int i=0;trans[i].Type[0]!=0;i++)cout<<"Type: "<<trans[i].Type<<" "<<trans[i].howMuch<<endl;
	return;
}
User::User(const char Name[]):ID(IDcounter),Account(0,IDcounter),transCounter(1)
{
	strcpy(name,Name);
	memset(trans,0,sizeof(Transs)*100);
	cout<<"User constructed\n";
	IDcounter++;
}
int User::IDcounter=0;
