#include <iostream>
#include "mytime.h"

using namespace std;

int main()
{
	Time weeding(4,35);
	Time waxing(2,47);
	Time tatol;
	Time diff;
	Time adjust;

	cout<<"weeding time =";
	weeding.Show();
	cout<<endl;

	cout<<"waxing time ="<<waxing<<endl;

	cout<<"tatol woking time =";
	tatol=weeding + waxing;
	cout<<tatol<<endl;
	
	diff=weeding - waxing;
	cout<<"weeding time - waxing time =";
	diff.Show();
	cout<<endl;

	adjust=tatol * 1.5;
	cout<<"adjust time is "<<adjust<<endl;

	system("pause");
	return 0;
}


