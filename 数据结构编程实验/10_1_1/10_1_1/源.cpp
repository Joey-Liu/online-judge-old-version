#include <iostream>
using namespace std;

int lowbit(int n)
{
	return n & -n;
}

int main()
{
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		int num;
		cin>>num;
		cout<<num - lowbit(num) + 1<<" "<<num + lowbit(num) -1<<endl;
	}
}