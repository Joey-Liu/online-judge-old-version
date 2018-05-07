#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

void output(int n)
{
	cout<<n<<" ";
}

int main()
{
	list<int> one(5,2);
	int stuff[5]={1,2,4,8,6};
	
	list<int> two;
	two.insert(two.begin(),stuff,stuff + 5);

	int more[6] = {6,4,2,4,6,5};
	list<int> three(two);
	three.insert(three.end(),more,more + 6);

	cout<<"List one: ";
	for_each(one.begin(),one.end(),output);
	
	cout<<endl<<"List two: ";
	for_each(two.begin(),two.end(),output);

	cout<<endl<<"List Three: ";
	for_each(three.begin(),three.end(),output);

	three.remove(2);
	cout<<endl<<"List Three remove 2s: ";
	for_each(three.begin(),three.end(),output);

	three.splice(three.begin(),one);
	cout<<endl<<"Lisr Three after splice (one): ";
	for_each(three.begin(),three.end(),output);

	cout<<endl<<"List one: ";
	for_each(one.begin(),one.end(),output);

	three.unique();

	cout<<endl<<"List Three after unique: ";
	for_each(three.begin(),three.end(),output);

	three.sort();
	three.unique();
	cout<<endl<<"List Three after unique and sorted: ";
	for_each(three.begin(),three.end(),output);
	
	two.sort();
	three.merge(two);
	cout<<endl<<"Sorted two and merged into three: ";
	for_each(three.begin(),three.end(),output);
	cout<<endl;

	system("pause");
	return 0;
}

