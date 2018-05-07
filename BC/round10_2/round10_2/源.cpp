#include <iostream>
using namespace std;
const int maxn = 10000000;

int s[]
long long int gcd(long long int a,long long int b) //a > b
{
	if(b==0)
		return a;
	else
		return gcd(b,a % b);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	long long int x,y,k,g,st;
	scanf("%d",&casenum);
	while(casenum--)
	{
		scanf("%lld %lld %lld",&x,&y,&k);
		if(x < y)
		{
			long long int t = x;
			x = y;
			y = t;
		}

		g = gcd(x,y);
		long long int index = 0;
		for(int i = 1;(long long int)i * i <= g;i++)
		{
			if(i * i==g)

		}

		bool flag = false;
		
		if(!flag)
			printf("-1\n");
	}
	return 0;
}