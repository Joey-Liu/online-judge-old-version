#include <iostream>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];

long caculate(int a[],int n)
{
	long time =0;
	for(int i =0;i < n;i++)
	{
		if(0==i)
			time += a[0]*6;
		else
		{
			if(a[i] >= a[i-1])
				time +=(a[i] - a[i-1])*6;
			else if(a[i] < a[i-1])
				time +=(a[i-1] - a[i])*4;
		}
	}
	time += 5*n;
	return time;
}

int main()
{
	int n;
	cin>>n;
	while(n)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i < n;i++)
			cin>>a[i];
		cout<<caculate(a,n)<<endl;
		cin>>n;
	}
	return 0;
}
