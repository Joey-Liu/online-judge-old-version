#include <iostream>
using namespace std;

const int maxn = 350 + 30;
int row;
int tri[maxn][maxn];
int dp[maxn][maxn];//dp[i][j] 从tri[i][j] 到 底部 的最大值

void init()
{
	cin>>row;
	for(int i = 1;i <= row;i++)
		for(int j = 1;j <= i;j++)
			cin>>tri[i][j];

}

int solve(int i,int j)
{
	int res = 0;
	if(-1 != dp[i][j])
		return dp[i][j];
	else
	{
		if(i==row)
			res = tri[i][j];
		else
		{
			res = tri[i][j] + max(solve(i + 1,j),solve(i + 1,j + 1));
		}
		dp[i][j] = res;
		return res;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	memset(dp,-1,sizeof(dp));
	cout<<solve(1,1)<<endl;
	return 0;
}
