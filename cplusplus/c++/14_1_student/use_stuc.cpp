#include <iostream>
#include "studentc.h"
using namespace std;

void set(Student & sa,int n);
const int pupils=3;
const int quizzes=5;

int main()
{
	Student Ada[pupils]=
	{Student(quizzes),Student(quizzes),Student(quizzes) };
	int i=0;
	
	//cout<<"Please enter student's information:(q to quit):";
	for(;i<pupils;i++)
	{
		//string temp;
		//cin>>temp;
		//if("q"==temp)
		//	break;
		set(Ada[i],quizzes);
	}
	cout<<endl<<"Student list:"<<endl;
	for(i=0;i<pupils;i++)
		cout<<Ada[i].Name()<<endl;
	cout<<"\nStudent Results:\n";
	for(i=0;i<pupils;i++)
	{
		cout<<Ada[i]<<endl;
		cout<<"Average: "<<Ada[i].Average()<<endl;
	}
	cout<<"Done\n";
}

void set(Student & sa,int n)
{
	cout<<"Please enter student's name:";
	getline(cin,sa);
	cout<<"Please enter "<<n<<" quiz scores:\n";
	for(int i=0;i<n;i++)
		cin>>sa[i];
	while(cin.get()!='\n')
		continue;
}

