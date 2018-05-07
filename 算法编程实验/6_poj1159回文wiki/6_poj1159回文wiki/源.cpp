#include <iostream>
using namespace std;

const int maxn = 5000 + 30;
short dp[maxn][maxn];

int N;
char str[maxn];

void solve()
{
	memset(dp,0,sizeof(dp));
	
	for(int len = 1;len < N;len++)
		for(int lp = 1;lp + len <= N;lp++)
		{
			if(str[lp]==str[lp + len])
				dp[lp][len + lp] = dp[lp + 1][lp + len - 1];
			else
			{
				dp[lp][len + lp] = min(dp[lp + 1][len + lp] + 1,dp[lp][lp + len - 1] + 1);
			}
		}
	cout<<dp[1][N]<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>N>>(str + 1);
	solve();
	return 0;
}