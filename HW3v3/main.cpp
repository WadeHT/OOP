#include<iostream>
#include"user.cpp"
using namespace std;
int main(void)
{
	//create User
	User u1("John");
	User u2("Mary");
	Account &a1 = u1.getAccount();
	//normal deposit
	a1.deposit(400);
	cout << "Balance of: " << u1.getUsername() <<" ID is: "<<u1.getID()<< " account is: " << a1.getAmount()<< endl;
	cout<<"\n\n";
	//normal withdraw
	if(a1.withdraw(100))cout << "Balance of: " << u1.getUsername() <<" ID is: "<<u1.getID()<< " account is: " << a1.getAmount()<< endl;
	else cout<<"False\n";
	//illegal withdraw
	if(a1.withdraw(500))cout << "Balance of: " << u1.getUsername() <<" ID is: "<<u1.getID()<< " account is: " << a1.getAmount()<< endl;
	else cout<<"False withdraw\n";
	cout<<"\n\n";
	//normal TransferMoney
	if(a1.transferMoney(u2.getAccount(), 200))
	{
		cout << "Balance of: " << u1.getUsername() <<" ID is: "<<u1.getID()<< " account is: " << a1.getAmount()<< endl;
		cout << "Balance of: " << u2.getUsername() <<" ID is: "<<u2.getID()<< " account is: " << u2.getAccount().getAmount()<< endl;
	}
	else cout<<"False transferMoney\n";
	//illegal TransferMoney
	if(a1.transferMoney(u2.getAccount(), 500))
	{
		cout << "Balance of: " << u1.getUsername() <<" ID is: "<<u1.getID()<< " account is: " << a1.getAmount()<< endl;
		cout << "Balance of: " << u2.getUsername() <<" ID is: "<<u2.getID()<< " account is: " << u2.getAccount().getAmount()<< endl;
	}
	else cout<<"False transferMoney\n";
	cout<<"\n\n";
	//trans record of u1
	u1.getTrans();
	cout<<"\n\n";
	//transaction record of u1
	u1.getRecord();
	return 0;
}