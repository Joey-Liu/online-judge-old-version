#include <iostream>
using namespace std;

const int maxn = 10000 + 10;
int a[maxn];
int e[5][5];
int dp[5][5][maxn];
int num;

int solve(int x,int y,int k)
{
	if(dp[x][y][k] != -1)
		return dp[x][y][k];
	else
	{
		if(k==num)
			return dp[x][y][k] = min(e[x][a[k]],e[y][a[k]]);
		else
			return dp[x][y][k] = min(solve(a[k],y,k + 1) + e[x][a[k]],solve(x,a[k],k + 1) + e[y][a[k]]);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>num;
	
	for(int i = 1;i <= num;i++)
		cin>>a[i];

	for(int i = 1;i <= 4;i++)
	{
		e[i][i] = 1;
		e[0][i] = 2;
	}

	e[1][2] = e[1][4] = e[2][1] = e[2][3] = e[3][2] = e[3][4] = e[4][1] = e[4][3] = 3;
	e[1][3] = e[3][1] = e[2][4] = e[4][2] = 4;

	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0,1)<<endl;
	return 0;
}