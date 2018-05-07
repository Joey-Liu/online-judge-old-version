#include <iostream>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];//珍珠需求量
int p[maxn];//珍珠价格 基于1
int dp[maxn];//dp[i] 在购买到 第i类珍珠时 的最少花费
int casenum;
int classnum;

void init()
{
	cin>>classnum;
	for(int i = 1;i <= classnum;i++)
		cin>>a[i]>>p[i];
}

void DP()
{
	memset(dp,100,sizeof(dp));
	dp[0] = 0;

	for(int i = 1;i <= classnum;i++)
		for(int j = 1;j <= i;j++)//从第i类珍珠向前 j 类用 i替代
		{
			int tmp = 0;
			for(int k = i - j + 1;k <= i;k++)
				tmp += a[k];
			tmp = (tmp + 10 )* p[i] + dp[i - j];

			dp[i] = min(dp[i],tmp);
		}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>casenum;
	while(casenum--)
	{
		init();
		DP();
		cout<<dp[classnum]<<endl;
	}
	return 0;
}