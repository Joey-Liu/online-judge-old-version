#include<iostream>
#include"person.h"
using namespace std;
int main()
{
	Person one;
	Person two("balalalablabl");
	Person three("Dimwiddy","Sam");
	one.show();
	cout<<endl;
	one.FomalShow();

	two.FomalShow();
	three.FomalShow();
	return 0;
}
