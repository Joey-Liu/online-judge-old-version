#include<iostream>
#include<string.h>
#include"classic.h"

using std::cout;
using std::cin;
using std::endl;

Cd::Cd(char* s1,char* s2,int n,double x)
{
	strcpy(performers,s1);
	strcpy(label,s2);
	selections=n;
	playtime=x;
}

Cd::Cd(const Cd & d)
{
	strcpy(performers,d.performers);
	strcpy(label,d.label);
	selections=d.selections;
	playtime=d.playtime;
}

Cd::Cd()
{
	performers[0]='\0';
	label[0]='\0';
	selections=0;
	playtime=0;
}

Cd::~Cd()
{}

void Cd::Report() const
{
	cout<<"performers: "<<performers<<endl;
	cout<<"label: "<<label<<endl;
	cout<<"selections: "<<selections<<endl;
	cout<<"playtime: "<<playtime<<endl;
}

Cd & Cd::operator =(const Cd & d)
{
	if(this==&d)
		return *this;
	strcpy(performers,d.performers);
	strcpy(label,d.label);
	selections=d.selections;
	playtime=d.playtime;
	return *this;
}


Classic::Classic(char* c1,char* c2,char* c3,int n,double x):Cd(c2,c3,n,x)
{
	strcpy(major,c1);
}


Classic::Classic(const Classic & cd):Cd(cd)
{
	strcpy(major,cd.major);
}


Classic::Classic():Cd()
{
	major[0]='\0';
}


Classic::~Classic()
{}


void Classic::Report() const
{
	Cd::Report();
	cout<<"major: "<<major<<endl;
}


Classic & Classic::operator =(const Classic & cd)
{
	if(this==&cd)
		return *this;
	Cd::operator =(cd);
	strcpy(major,cd.major);
	return *this;
}

