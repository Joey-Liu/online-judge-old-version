#include <iostream>
using namespace std;

const int maxn = 15000 + 100;
int dp[25][maxn];//dp[i][j] 使用前i个物体时 平衡度为j 的方法总数
int C,G;
int h[25];//钩子位置
int g[25];//重量

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>C>>G;
	
	for(int i = 1; i<= C;i++)
		cin>>h[i];
	for(int i = 1;i <= G;i++)
		cin>>g[i];

	memset(dp,0,sizeof(dp));
	dp[0][7500] = 1;

	for(int i = 1;i <= G;i++)
	{
		for(int j = -7500;j <= 7500;j++)
		{
			if(dp[i - 1][j + 7500] != 0)//此子状态可用时,产生相应新的状态，比dfs 暴搜节省大量时间
			{
				for(int k = 1;k <= C;k++)
					dp[i][j + 7500 + g[i] * h[k]] += dp[i - 1][j + 7500];
			}
		}//for int j
	}//for int i
	cout<<dp[G][7500]<<endl;
	return 0;
}