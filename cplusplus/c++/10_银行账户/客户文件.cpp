#include<iostream>
#include"account.h"
using namespace std;
int main()
{
	cout<<"��ʼ���ԣ�\n";
	Account account1("liu","13121144",1000);					//
    account1.show();
	Account account2;
	account2.show();


	double m1,m2;
	cout<<"Enter the money you want to take from liu:";
	cin>>m1;
	account1.take(m1);
	account1.show();
	
	
	cout<<"Enter the money you want to save in account2:";
	cin>>m2;
	account2.save(m2);
	account2.show();

	
	
	cout<<"Done\n";
	return 0;
}
