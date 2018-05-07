#include <iostream>
using namespace std;

const int maxn = 100;
int dp[maxn][maxn][maxn];

int solve(int x,int y,int z)

{
	if(x <= 0 || y <= 0 || z <= 0)
	{	
		if(x < 0 || y < 0 || z < 0)
			return 1;
		else
			return (dp[0][0][0] = 1);
	}

	if(dp[x][y][z] != 2139062143)
		return dp[x][y][z];
	
	if(x <= 0 || y <= 0 || z <= 0)
	{	
		if(x < 0 || y < 0 || z < 0)
			return 1;
		else
			return (dp[0][0][0] = 1);
	}
	else if(x > 20 || y > 20 || z > 20)
	{
		return (dp[x][y][z] = solve(20,20,20));
	}
	else if(x < y && y < z)
	{
		dp[x][y][z -1] = solve(x,y,z-1);
		dp[x][y - 1][z - 1] = solve(x, y - 1,z - 1);
		dp[x][y -1][z] = solve(x,y - 1,z);
		return (dp[x][y][z] = dp[x][y][z -1] + dp[x][y - 1][z - 1] - dp[x][y -1][z]);
	}
	else
	{
		return (dp[x][y][z] = solve(x- 1,y,z) + solve(x- 1,y - 1,z) + solve(x- 1,y,z- 1) - solve(x -1,y -1,z- 1));
	}
}

int main()
{
	freopen("C.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(dp,0x7f,sizeof(dp));
	int a,b,c;
	cin>>a>>b>>c;
	while(a != -1 || b != -1 || c != -1)
	{
		int res = solve(a,b,c);
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<res<<endl;
		cin>>a>>b>>c;
	}
	return 0;
}