#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 100;
int a[maxn];

int main()
{
	int num;
	while(cin>>num)
	{
		for(int i = 0;i < num;i++)
			cin>>a[i];

		sort(a,a + num);
		cout<<a[num - 1]<<endl;
		if(num==1)
			cout<<"-1"<<endl;
		else
		{
			for(int i = 0;i < num - 1;i++)
				cout<<a[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}