#include <iostream>
#include <string>
#include <list>
#include <sstream>

const int maxn = 1000 + 50;
using namespace std;
int reduce(int ar[],int n);

int main()
{
	cout<<"Enter some numbers please:"<<endl;
	string str;
	getline(cin,str);
	istringstream ss(str);
	
	int num[maxn];
	int i =0;
	while(ss>>num[i])
	{
		i++;
	}

	int num_size = reduce(num,i);

	for(int i =0;i < num_size;i++)
		cout<<num[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}

int reduce(int ar[],int n)
{
	cout<<"STL on line!\n";
	list<int> temp(ar,ar + n);
	temp.sort();
	temp.unique();
	copy(temp.begin(),temp.end(),ar);
	return temp.size();
}
