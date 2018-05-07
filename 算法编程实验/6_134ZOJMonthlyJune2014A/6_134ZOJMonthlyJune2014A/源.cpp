#include <iostream>
using namespace std;

const int maxn = 100 + 10;
const int mods = 5767169;
int dp[maxn];
int A,B,a,b,n;

int solve(int n)
{
	if(n < 0)
		return 0;
	if(0==n)
		return (dp[n] = 1);
	if(dp[n] != 2139062143)
		return dp[n];

	if(n > 0)
	{
		int res = A * solve(n - a) % mods + B * solve(n -b) % mods;
		return (dp[n] = (res % mods) );
	}
}

int main()
{
	while(cin>>A>>B>>a>>b>>n)
	{
		memset(dp,0x7f,sizeof(dp));
		cout<<solve(n)<<endl;
	}
	return 0;
}