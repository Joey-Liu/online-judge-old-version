#include <iostream>
#define SIZE 1299800
using namespace std;

const int maxn = 100000 + 5;
bool u[SIZE];
int su[maxn];
int ans[SIZE];
int num = 0;//

void prime()
{
	memset(u,true,sizeof(u));
	u[0] = u[1] = false;
	for(int i = 2;i < SIZE;i++)
		if(u[i])
		{
			for(int j = 2;j * i < SIZE;j++)
				u[j * i] = false;
		}
	for(int i = 2;i < SIZE;i++)
	{
		if(u[i])
			su[++num] = i;
	}
}

void solve()
{
	int lp,rp;
	memset(ans,0,sizeof(ans));
	for(int i = 2;i <= num;i++)
	{
		lp = su[i - 1] + 1;
		rp = su[i] - 1;
		while(lp <= rp)
		{
			ans[lp] = su[i] - su[i - 1];
			lp++;
		}
	}
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("out.txt","w",stdout);
	prime();
	solve();
	int n;
	while(cin>>n && n != 0)
		cout<<ans[n]<<endl;
	return 0;
}