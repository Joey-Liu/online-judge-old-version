#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 250;//大米的中类经过处理后可能有很多种
int p[maxn];
int h[maxn];//p h 根据后面加权会发生改变

int c[maxn];
int dp[maxn];
int n,m;//n money m kinds of rice
int casenum;
int ori;//存储原来的m

void init()
{
	memset(p,0,sizeof(p));
	memset(h,0,sizeof(h));
	memset(c,0,sizeof(c));
	cin>>n>>m;
	//ori = m;
	for(int i = 1;i <= m;i++)
		cin>>p[i]>>h[i]>>c[i];
}

/*
void trans()
{
	for(int i = 1;i <= m;i++)
	{
		int k = 0;
		while(c[i] - pow(double(2),double(k)) + 1 > 0)
		{
			p[m + 1] = pow(double(2),double(k)) * p[i];
			h[m + 1] = pow(double(2),double(k)) * h[i];
			c[i] -= pow(double(2),double(k));
			m++;
			k++;
		}
		if(c[i])
		{
			p[m + 1] = c[i] * p[i];
			h[m + 1] = c[i] * h[i];
			m++;
		}
	}
}
*/


void ZOP()
{	
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= c[i];j++)
			for(int v = n;v >= p[i];v--)
				dp[v] = max(dp[v],dp[v - p[i]] + h[i]);

}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>casenum;
	while(casenum--)
	{
		init();
		//trans();
		ZOP();
		cout<<dp[n]<<endl;
	}
	return 0;
}