#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 100 + 10;
int dp[maxn][maxn];
int height[maxn][maxn];
int R,C;				//矩阵行列值

int DP(int m,int n)
{
	if(-1 != dp[m][n])//如果这个问题曾经计算过
		return dp[m][n];
	if(m < 0 || m >= R)
		return 0;
	if(n < 0 || n >= C)	//到达行 列边界
		return 0;

	int Ln,Rn,Un,Dn;
	if(n - 1 < 0 || height[m][n - 1] >= height[m][n])				//左边较高或到达边界
		Ln = 0;
	else                                                     //否则就应该等于左边数目
		Ln = DP(m,n - 1);				

	if(n + 1 >= C || height[m][n + 1] >= height[m][n])			//右边
		Rn = 0;
	else
		Rn = DP(m,n + 1);
	
	if(m - 1 < 0 || height[m - 1][n] >= height[m][n])				//上边
		Dn = 0;
	else
		Dn = DP(m - 1,n);

	if(m + 1 >= R || height[m + 1][n] >= height[m][n])			//下边
		Un = 0;
	else
		Un = DP(m + 1,n);
	
	int record = max(max(Ln,Rn),max(Dn,Un)) + 1;
	return record;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	memset(height,0,sizeof(height));
	
	cin>>R>>C;
	for(int i = 0;i < R;i++)
		for(int j = 0;j < C;j++)
			cin>>height[i][j];

	for(int i = 0;i < R;i++)
	{
		for(int j = 0;j < C;j++)
		{
			if (-1 == dp[i][j])			//dp[i][j] = -1时表示这一点还没有探索到
				dp[i][j] = DP(i,j);
		}
	}
	
	int max = 0;
	for(int i =0;i < R;i++)
	{
		for(int j =0;j < C;j++)
		{
			if(max < dp[i][j])
				max = dp[i][j];
		}
	}
	cout<<max<<endl;
	system("pause");
	return 0;
}