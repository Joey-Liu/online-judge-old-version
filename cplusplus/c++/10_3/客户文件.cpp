#include<iostream>
#include"move.h"

using namespace std;
int main()
{
	Move first,second,final;
	int x,y;
	cout<<"Please enter the first place:\n"
		<<"x=";
	cin>>x;
	cout<<"y=";
	cin>>y;
	first.reset(x,y);
	first.showmove();


	//Move second;
	cout<<"Please enter the second place:\n"
		<<"x=";
	cin>>x;
	cout<<"y=";
	cin>>y;
	second.reset(x,y);
	second.showmove();

	//Move final;
	cout<<"The two things added:";
    final=first.add(second);
    final.showmove();
	return 0;
}

