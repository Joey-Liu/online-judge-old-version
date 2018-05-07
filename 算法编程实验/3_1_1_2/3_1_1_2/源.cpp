#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 10000000 + 10;
int u[maxn];
int su[maxn];
int num = 1;

void prime()
{
	memset(u,true,sizeof(u));
	for(int i = 2;i <= maxn;i++)
	{
		if(u[i])
			su[num++] = i;
		for(int j = 1;j < num;j++)
		{
			if(i * su[j] > maxn)
				break;
			u[i * su[j]] = false;
			if(i % su[j]==0)
				break;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	prime();
	int n;
	while(cin>>n)
	{
		if(n < 8)
			cout<<"Impossible."<<endl;
		else
		{
			if(n % 2==0)
			{
				cout<<"2 2 ";
				n -= 4;
			}
			else
			{
				cout<<"2 3 ";
				n -= 5;
			}
			for(int i = 1;i < n;i++)
			{
				if(u[n - su[i]])
				{
					cout<<su[i]<<" "<<n - su[i]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}