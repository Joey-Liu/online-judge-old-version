#include <iostream>
#include "brass.h"
#define CLIENT 40

using namespace std;

int main()
{
	Brass *p_client[CLIENT];
	string temp_name;
	long int temp_num;
	double temp_bal;
	int kind,i;				//i use for num of client
	
	for(i=0;i<CLIENT;i++)
	{
		cout<<"Please enter the name of the account:(q to qiut)\n";
		cin>>temp_name;
		if("q"==temp_name)
			break;

		cout<<"Enter the client's account number:";
		cin>>temp_num;

		cout<<"Enter opening balance:";
		cin>>temp_bal;

		do
		{
			cout<<"Enter 1 for Brass or enter 2 for BrassPlus:";
			cin>>kind;
			cout<<"kind="<<kind<<endl;
		}while((1!=kind) && (2!=kind));
		
		if(1==kind)
			p_client[i]=new Brass(temp_name,temp_num,temp_bal);
		else
		{	
			double ml,r;
			cout<<"Enter the overdraft limit: $";
			cin>>ml;
			cout<<"Enter the interest rate as a decimal fraction: ";
			cin>>r;
			p_client[i]=new BrassPlus(temp_name,temp_num,temp_bal,
									ml,r);
		}
		while(cin.get()!='\n')
			continue;
	}
	cout<<endl;

	for(int j=0;j<i;j++)
	{
		p_client[j]->ViewAcct();
		cout<<endl;
	}

	//for(;i>=0;i--)
	//	delete p_client[i];
	cout<<"Done!\n";

	system("pause");
	return 0;
}



		
