#include<iostream>
#include"person.h"
#include<string>
using namespace std;
Person::Person(const string &ln, const char *fn)
{
	int n = 0;
	//char* pn=fn;
	lname = ln;
	strcpy(fname, fn);
}

Person p("what", "hell");

void Person::show() const
{
	cout << "Firstname,lastname:" << fname << " " << lname << endl;
}

void Person::FomalShow() const
{
	cout << "Lastname,firstname:" << lname << " " << fname << endl;
}
