#include <iostream>
#include "string1.h"
using namespace std;

const int ArSize =10;
const int MaxLen =81;
int main()
{
	using namespace std;
	String name;
	cout<<"Hello, what is your name:";
	cin>>name;

	cout<<name<<",please enter uo to "<<ArSize
		<<"short sayings.(enter empty line to give up.)\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i=0;

	for(;i<ArSize;i++)
	{
		cout<<i+1<<":";
		cin>>sayings[i];
		if(!cin||'\0'==sayings[i][0])
			break;
	}

	int total=i;
	if(total>0)
	{
		cout<<"Here are your sayings:"<<endl;
		for(i=0;i<total;i++)
			cout<<i+1<<":"<<sayings[i]<<endl;

		int shortest=0;
		int first=0;
		for(i=1;i<total;i++)
		{
			if(sayings[shortest].lengh() > sayings[i].lengh())
				shortest=i;
			if(sayings[first] > sayings[i])
				first=i;
		}

		cout<<"The shortest sayings:"<<sayings[shortest]
			<<endl;
		
		cout<<"The first sayings:"<<sayings[first]
			<<endl;

		cout<<"The program used "<<String::Howmany()<<" sayings,see you\n";
	}
	else 
		cout<<"There is no saying,bye"<<endl;

	system("pause");
	return 0;
}



