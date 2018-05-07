#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 130;
int a[maxn];

int main()
{
	int num;
	while(cin>>num)
	{
		for(int i = 0;i < num;i++)
			cin>>a[i];

		sort(a,a + num);
		for(int i = 0;i < num;i++)
			cout<<a[i]<<" ";
		cout<<endl;

	}
	return 0;
}