#include<iostream>
#include"cow.h"
using namespace std;
Cow::Cow()
{
	name[0]='\0';
	hobby=NULL;
	weight=0.0;
}



Cow::Cow(const char* nm,const char* ho,double wt)
{
	strcpy(name,nm);
	hobby=new char[1+strlen(ho)];
	strcpy(hobby,ho);
	weight=wt;
}



Cow::Cow(const Cow & c)
{
	strcpy(name,c.name);
	hobby=new char [1+strlen(c.hobby)];
	strcpy(hobby,c.hobby);
	weight=c.weight;
}



Cow::~Cow()
{
	delete [] hobby;
}


Cow & Cow::operator=(const Cow & c)
{
	if(this==&c)
		return *this;
	delete []hobby;
	strcpy(name,c.name);
	hobby=new char[1+strlen(c.hobby)];
	strcpy(hobby,c.hobby);
	weight=c.weight;
	return *this;
}



void Cow::ShowCow() const
{
	cout<<"name:"<<name<<endl;
	cout<<"hobby:"<<hobby<<endl;
	cout<<"weight:"<<weight<<endl;
}

