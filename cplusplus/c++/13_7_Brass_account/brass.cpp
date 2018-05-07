#include <iostream>
#include "brass.h"
using namespace std;

Brass::Brass(const string & s,long int an,double bal)
{
	fullName=s;
	accNum=an;
	balance=bal;
}

void Brass::Deposit(double amt)
{
	if(amt<0)
		cout<<"Negetive deposit may not allowed"
			<<",deposit canceled."<<endl;
	else
		balance+=amt;
}

void Brass::Withdraw(double amt)
{
	if(amt<0)
		cout<<"Negetive withdraw may not allowed,"
			<<"withdraw canceled."<<endl;
	else if(amt>balance)
		cout<<"Withdraw amount of $"<<amt
			<<" exceeds your balance.\n"
			<<"Withdraw canceled.\n";
	else
		balance-=amt;
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const 
{
	cout<<"Client: "<<fullName<<endl;
	cout<<"Account number: "<<accNum<<endl;
	cout<<"Balance: "<<balance;
}

//////////////////////////BrassPLus methods
BrassPlus::BrassPlus(const string & s,long int an,
					 double bal,double ml,
					 double r) :Brass(s,an,bal)
{
	maxloan=ml;
	rate=r;
	owebank=0.0;
}

BrassPlus::BrassPlus(const Brass & ba,double bal,
					 double ml,double r) :Brass(ba)
{
	maxloan=ml;
	rate=r;
	owebank=0.0;
}

void BrassPlus::Withdraw(double amt)
{
	double bal=Balance();
	if(amt<bal)
		Brass::Withdraw(amt);
	else if(amt<maxloan + bal - owebank)
	{
		double advance=amt-bal;
		owebank+=advance*(rate+1.0);
		cout<<"Bank Adavance:"<<advance<<endl;
		cout<<"Finance charge:"<<advance*rate<<endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout<<"Credit limit exceeded.Transaction canceled.\n";
}

void BrassPlus::ViewAcct() const
{
	Brass::ViewAcct();
	cout<<"Maximun loan: $"<<maxloan<<endl;
	cout<<"Owed to bank: $"<<owebank<<endl;
	cout<<"Loan Rate: "<<100*rate<<"%.\n";
}






