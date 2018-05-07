#include<iostream>
#include"classic.h"
using namespace std;
void Bravo(const Cd & disk);

int main()
{
	Cd c1("Beatles","Capitol",14,35.5);
	Classic c2=Classic("Piano Sonata in B flat,Fantas in C",
		"Alfred Bredel","philips",2,51.17);
	Cd* pcd=&c1;

	cout<<"using object directly:\n";
	c1.Report();
	c2.Report();
	cout<<endl;


	cout<<"using type cd * pointer to objects:\n";
	pcd->Report();
	pcd=&c2;
	pcd->Report();
	cout<<endl;

	cout<<"Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout<<endl;

	cout<<"Testing assignment: ";
	Classic copy;
	copy=c2;
	copy.Report();
	cout<<endl;

	return 0;
}


void Bravo(const Cd & disk)
{
	disk.Report();
}



