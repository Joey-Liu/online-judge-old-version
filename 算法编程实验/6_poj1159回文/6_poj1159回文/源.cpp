#include <iostream>
using namespace std;

const int maxn = 3000 + 100;
char str[maxn];//基于1存储
int N;
int dp[maxn][maxn];//dp[i][j]表示 从i到j 最少添加的字符数量

int solve(int lp,int rp)
{
	if(dp[lp][rp] != -1)
		return dp[lp][rp];

	int ret;
	if(lp >= rp)
		ret = 0;
	else if(str[lp]==str[rp])
		ret = solve(lp + 1,rp -1);
	else
		ret = min(solve(lp,rp - 1) + 1,solve(lp+ 1,rp) + 1);
	return (dp[lp][rp] = ret);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>N;
	for(int i = 1;i <= N;i++)
		cin>>str[i];
	cout<<solve(1,N)<<endl;
	return 0;
}
