#include <iostream>
using namespace std;

const int maxn = 10000;
int prime[maxn] = {0};
int num_prime = 0;
int isNotPrime[maxn] = {1,1};

void makesu()
{
	for(int i = 2;i < maxn;i++)
	{
		if(!isNotPrime[i])
			prime[num_prime++] = i;
		for(int j = 0;j < num_prime && i * prime[j] < maxn;j++)
		{
			isNotPrime[i * prime[j]] = 1;
			if(!(i % prime[j]))
				break;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum,n,res,tmp;
	cin>>casenum;
	makesu();
	while(casenum--)
	{
		cin>>n;
		res = tmp = 0;
		for(int i = 0;i < num_prime && prime[i] < n;i++)
		{
			if(tmp < n % prime[i])
			{
				tmp = n % prime[i];
				res = prime[i];
			}
		}
		cout<<res<<endl;
	}
	return 0;
}