#include <iostream>
#include "workemi.h"
using namespace std;

const int SIZE=5;
int main()
{
	Worker *lolas[SIZE];
	int ct;

	for(ct=0;ct<SIZE;ct++)
	{
		char choice;
		cout<<"Enter the employee category:\n"
			<<"w: waiter  s: singer"
			<<"t: singingwaiter  q: quit\n";
		cin>>choice;
		while(NULL==strchr("wstq",choice))
		{
			cout<<"Please enter w,s,t or q :";
			cin>>choice;
		}
		if('q'==choice)
			break;
		switch(choice)
		{
			case 'w': lolas[ct]= new Waiter;
				  break;
			case 's': lolas[ct]=new Singer;
				  break;
			case 't': lolas[ct]=new SingingWaiter;
				  break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	cout<<"Here is your staff:\n";
	int i;
	for(i=0;i<ct;i++)
	{
		cout<<endl;
		lolas[i]->Show();
	}
	
	for(i=0;i<ct;i++)
		delete lolas[i];
	cout<<"Done!\n";
	system("pause");
	return 0;
}




