#include <iostream>
#include "cd.h"
using namespace std;

void Bravo(const Cd & disk);
int main()
{
	Cd c1("Beatles","Capital",41,35.5);
	Classic c2("Piano Sonata int a B flat,Fantansiz in C",
			"Afred Bredenl","Philips",2,57.17);
	Cd *pcd=&c1;

	cout<<"Using object directly:"<<endl;
	c1.Report();
	c2.Report();

	cout<<"Using type *cd pointer to objects:\n";
	pcd->Report();
	pcd=&c2;
	pcd->Report();

	cout<<"Calling a function with a cd reference:\n";
	Bravo(c1);
	Bravo(c2);

	cout<<"Testing assingment:\n";
	Classic copy;
	copy=c2;
	copy.Report();

	system("pause");
	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}

