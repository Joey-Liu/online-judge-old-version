#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include<string>
using namespace std;
class Account
{
private:
	string name;
	string number;
	double money;
public:
	Account(string name_, string number, double n);
	Account();
	~Account();
	void show();
	void save(double num);
	void take(double num);
};
#endif
