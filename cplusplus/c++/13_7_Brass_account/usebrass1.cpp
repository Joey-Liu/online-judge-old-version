#include <iostream>
#include "brass.h"
using namespace std;

int main()
{
	Brass Piggy("Porelot Pigg",381299,4000.0);
	BrassPlus Hoggy("Horatio Hogg",382288,3000);

	Piggy.ViewAcct();
	cout<<endl<<endl;
	Hoggy.ViewAcct();
	cout<<endl;

	cout<<"Depositing $1000 into the Hoggy account:\n";
	Hoggy.Deposit(1000);

	cout<<"New balance: $"<<Hoggy.Balance()<<endl;
	cout<<"Withdraw $4200 from Piggy:\n";
	Piggy.Withdraw(4200);
	cout<<"Piggy account balance: $"<<Piggy.Balance()<<endl;


	cout<<"Withdraw $4200 from Hoggy:\n";
	Hoggy.Withdraw(4200);
	Hoggy.ViewAcct();

	system("pause");
	return 0;
}



