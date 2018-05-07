#include <iostream>
using namespace std;

const int  maxn = 1000 + 100;
int cost[maxn];
int value[maxn];
int dp[maxn];
int casenum;
int num,vo;

void init()
{
	cin>>num>>vo;
	for(int i = 1;i <= num;i++)
		cin>>value[i];
	for(int i = 1;i <= num;i++)
		cin>>cost[i];
}

void DP()
{
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= num;i++)
		for(int v = vo;v >= cost[i];v--)
			dp[v] = max(dp[v],dp[v - cost[i]] + value[i]);
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
		cout<<dp[vo]<<endl;
	}
	return 0;
}