#include<iostream>
#include"account.h"
using namespace std;
Account::Account(string name_, string number_, double n)
{
	cout<<"Constructor using"<<name_<<"called\n";
	name=name_;
	number=number_;
	if(n<0)
	{
		cout<<"Number of money can not be negetive,it will be set to 0.\n";
		money=0;
	}
	else 
		money=n;
}



Account::Account()
{
	name="No name";
	number="Nothing";
	money=0.0;
}




Account::~Account()
{
};



void Account::show()
{
	cout<<"Name: "<<name<<endl
		<<"Number: "<<number<<endl
		<<"Money: "<<money<<endl;
}


void Account::save(double num)
{
	if(num<0)
		cout<<"Number of money can not be negetive,Transaction id aborted.\n";
    else 
		money=money+num;
}



void Account::take(double num)
{
	if(num<0)
		cout<<"Number of money can not be negetive,Transaction id aborted.\n";
	else if(num>money)
		cout<<"You can't take more than you have"<<endl;
	else
		money=money-num;
}



