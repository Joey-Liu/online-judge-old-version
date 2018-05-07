#include <iostream>
using namespace std;

const int maxp=2000,n=10000;
int prime[maxp],total=0;

bool isprime(int k)
{
	for(int i=0;i<total;i++)
		if(0==k%prime[i])
			return false;
	return true;
}

int main()
{
	for(int i=2;i<n;i++)
		if(isprime(i))
			prime[total++]=i;
	prime[total]=n+1;
	
	int n;
	cin>>n;
	while(n > 0)
	{
		int p[maxp];
		memset(p,0,sizeof(p));
		int max=0;
		
		for(int i=1;i<=n;i++)					//开始阶乘
		{
			int m=i;
			for(int j=0;j<total;j++)				//开始除以素数
			    while(0==m%prime[j])
				{		
					m=m/prime[j];
					p[j]++;
					if(j>max)
						max=j;
				}
		}
		for(int i_o=0;i_o<=max;i_o++)
			cout<<p[i_o]<<" ";
		cout<<endl;
		cin>>n;
	}
	system("pause");
	return 0;
}

						
						