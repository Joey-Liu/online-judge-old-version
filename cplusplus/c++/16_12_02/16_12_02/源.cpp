#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;
bool FillNumbers(int & n);
void Output(int n) {cout<<n<<" "; }

int main()
{
	list<int> one;
	list<int> two;
	int temp;
	cout<<"Please enter the first group of numbers: ";
	while(FillNumbers(temp))
		one.push_back(temp);
	
	cout<<"\nPlease enter the second group of numbers: ";
	while(FillNumbers(temp))
		two.push_back(temp);

	cout<<"List 1: ";
	for_each(one.begin(),one.end(),Output);

	cout<<endl<<"List 2: ";
	for_each(two.begin(),two.end(),Output);
	cout<<endl;

	cout<<"Enter the number you don't like in list 1: ";
	int nu;
	cin>>nu;
	
	one.remove(nu);
	cout<<"List 1: ";
	for_each(one.begin(),one.end(),Output);
	cout<<endl;

	one.sort();
	two.sort();
	cout<<"List 1: ";
	for_each(one.begin(),one.end(),Output);
	cout<<endl;
	for_each(two.begin(),two.end(),Output);
	cout<<endl;

	cout<<"Let make them into one group.\n";
	one.splice(one.end(),two);
	for_each(one.begin(),one.end(),Output);

	cout<<"After unique & sorted: ";
	one.unique();
	one.sort();
	for_each(one.begin(),one.end(),Output);
	cout<<endl;

	system("pause");
	return 0;
}

bool FillNumbers(int & n)
{
	cout<<"Enter the number(q to quit):";
	if(!(cin>>n))							///////////////////////////
	{
		cin.clear();
		while(cin.get() != '\n')
			continue;
		return false;
	}
	return true;
}
