#include <iostream>
#include "workemi.h"
using namespace std;

//worker methods
Worker::~Worker() {}

//protected methods
void Worker::Data() const
{
	cout<<"Name: "<<fullname<<endl;
	cout<<"Employee ID: "<<id<<endl;
}

void Worker::Get()
{
	getline(cin,fullname);
	cout<<"Enter worker's ID: ";
	cin>>id;
	while(cin.get()!='\n')
		continue;
}

//Waiter methods
void Waiter::Set()
{
	cout<<"Enter waiter's name: ";
	Worker::Get();
	Get();		//waiter的get（）方法在后面定义
}

void Waiter::Show() const
{
	cout<<"Category: waiter\n";
	Worker::Data();
	Data();     //在后面定义
}

//protected methods
void Waiter::Data() const
{
	cout<<"Panache rating: "<<panache<<endl;
}

void Waiter::Get()
{
	cout<<"Enter waiter's panache rating: ";
	cin>>panache;
	while(cin.get()!='\n')
		continue;
}

//singer methods
char *Singer::pv[Singer::Vtypes]={"other","alto","contralto",
				"soprano","bass","baritone","tenor"};
void Singer::Set()
{
	cout<<"Enter singer's name: ";
	Worker::Get();
	Get();		//在后面定义
}

void Singer::Show() const
{
	cout<<"Category: singer\n";
	Worker::Data();
	Data();		//same as above
}


//protected methods
void Singer::Data() const
{
	cout<<"Vocal range: "<<pv[voice]<<endl;
}

void Singer::Get() 
{
	cout<<"Enter number of singer's vocal range:\n";
	int i;
	for(i=0;i<Vtypes;i++)
	{
		cout<<i<<": "<<pv[i]<<"  ";
		if(3==i%4)
			cout<<endl;
	}
	if(0!=i%4)
		cout<<endl;
	cin>>voice;
	while(cin.get()!='\n')
		continue;
}

//SingingWaiter methods
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set()
{
	cout<<"Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout<<"Category: singing waiter\n";
	Worker::Data();
	Data();
}

	

















