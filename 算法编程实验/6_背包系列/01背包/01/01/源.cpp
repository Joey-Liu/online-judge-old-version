//一维数组dp
#include <iostream>
#define	SIZE 1000
using namespace std;

const int maxn = 100 + 10;
int cost[maxn];
int value[maxn];
int vo;
int num;
int dp[SIZE];

void init()
{
	cin>>vo>>num;
	for(int i = 1;i <= num;i++)
		cin>>cost[i]>>value[i];
}

/*
void DP()
{
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= num;i++)
		for(int v = vo;v >= cost[i];v--)//容量小于 cost[i]的不影响
			dp[v] = max(dp[v],dp[v - cost[i]] + value[i]);
}
*/

void DP()
{
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= num;i++)
	{
		int bound = 0;
		for(int j = i;j <= num;j++)
			bound += cost[j];

		//通过减少不必要的子问题 进行优化
		for(int v = vo;v >= max(v - bound,cost[i]);v--)
			dp[v] = max(dp[v],dp[v - cost[i]] + value[i]);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	DP();
	cout<<dp[vo]<<endl;
	return 0;
}