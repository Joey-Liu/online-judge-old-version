#include<iostream>
#include"cow.h"
using namespace std;
int main()
{
//	cout<<"1";
	Cow first("Dave","Playing",130);
//	cout<<"2";
	first.ShowCow();
//	cout<<"3";
	Cow second("Andy","Nothing",50);			//damn
	second.ShowCow();
	second=first;
	cout<<"\nThen:";
	second.ShowCow();
	return 0;
}
