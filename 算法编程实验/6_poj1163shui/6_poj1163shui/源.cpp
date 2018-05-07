#include <iostream>
using namespace std;
const int maxn = 100 + 10;

int number[maxn][maxn];
int dp[maxn][maxn];//从i，j到达最低部的最大数值
int cols;

int triangle(int m,int n)
{
	int maxnum = 0;
	if(-1 != dp[m][n])
		return dp[m][n];

	if(cols == m)
		maxnum = number[m][n];
	else
		maxnum = number[m][n] + max(triangle(m + 1,n),triangle(m + 1,n + 1));

	return dp[m][n] = maxnum;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>cols;
	for(int i = 1;i <= cols;i++)
		for(int j = 1;j <= i;j++)
			cin>>number[i][j];
	
	triangle(1,1);
	cout<<dp[1][1]<<endl;
	return 0;
}