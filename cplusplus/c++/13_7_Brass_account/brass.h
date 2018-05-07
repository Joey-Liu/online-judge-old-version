#ifndef BRASS_H_
#define BRASS_H_
#include <string>

using std::string;

class Brass
{
private:
	string fullName;
	long int accNum;
	double balance;
public:
	Brass(const string & s="no body",long int an=-1,
		double bal=0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

class BrassPlus :public Brass
{
private:
	double maxloan;
	double rate;
	double owebank;
public:
	BrassPlus(const string & s="no body",long int an=-1,
		double bal=0.0,double ml=500,
		double r=0.11125);
	BrassPlus(const Brass & ba,double bal=0.0,
		double ml=500,double r=0.11125);
	
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;

	void ResetMax(double m) { maxloan=m; }
	void ResetRate(double r) { rate=r; }
	void ResetOwes() { owebank=0; }
};

#endif
	
