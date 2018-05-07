/*
#include <iostream>
#include <math.h>
#include <memory.h>
using namespace std;

const int maxn = 10010;
bool u[maxn];
int su[maxn];//begin at 1
int dp[maxn];//dp[i] 序列前i项和
int num = 0;
int seq;//序列长度
int se[maxn];//序列 begin at 1

void prime()
{
	memset(u,true,sizeof(u));
	u[0] = u[1] = false;
	for(int i = 2;i < maxn;i++)
		if(u[i])
			for(int j = 2;i * j < maxn;j++)
				u[i * j] = false;

	for(int i = 2;i < maxn;i++)
		if(u[i])
			su[++num] = i;
}

bool judge_prime(int n)
{
	if(n < maxn)
		return u[n];

	for(int i = 1; su[i] <= sqrt(n);i++)
		if(n % su[i]==0)
			return false;
	return true;
}

void solve()
{
	for(int i = 1;i <= seq;i++)
		dp[i] = se[i];
	for(int i = 2;i <= seq;i++)
		dp[i] += dp[i - 1];

	for(int len = 2;len <= seq;len++)
		for(int lp = 1;lp + len - 1 <= seq;lp++)
		{
			if(judge_prime(dp[lp + len - 1] - dp[lp] + se[lp]) )
			{
				cout<<"Shortest primed subsequence is length "<<len<<": ";
				for(int i = lp;i < lp + len - 1;i++)
					cout<<se[i]<<" ";
				cout<<se[lp + len - 1];
				cout<<endl;
				return;
			}
		}//for int lp

	cout<<"This sequence is anti-primed."<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	prime();
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		cin>>seq;
		for(int i = 1;i <= seq;i++)
			cin>>se[i];
		solve();
	}
	return 0;
}
*/

#include <iostream>
using namespace std;

bool solve(int num)
{
	int num_co = num;
	int a[4];
	int index = 3;
	while(num != 0)
	{
		a[index] = num % 10;
		index--;
		num /= 10;
	}
	for(int i = 0;i < 3;i++)
	{
		for(int j = i + 1;j < 4;j++)
		{
			int su = a[i] * 10 + a[j];
			if(0==su)
				continue;
			if(0==num_co % su)
			{
				int m = 0,n = 0;//剩下的两个数字
				while(m==i || m==j)
					m++;
				while(n==i || n==j || n==m)
					n++;

				int bn = num_co / su;
				int b = bn % 10;
				int c = bn / 10;
				if( (b==a[m] && c==a[n]) || (b==a[n] && c==a[m]) )
					return true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("out.txt","w",stdout);
	for(int i = 1001;i < 10000;i++)
		if(solve(i))
			cout<<i<<"  ";
	return 0;
}