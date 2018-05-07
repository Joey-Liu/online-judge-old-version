#include <iostream>
#define SIZE 1100
using namespace std;

const int maxn = 100+ 10;
int cost[maxn];
int value[maxn];
int dp[SIZE];
int num;//物品个数
int vo;//体积

void init()
{
	cin>>vo>>num;
	for(int i = 1;i <= num;i++)
		cin>>cost[i]>>value[i];
}

/*
void DP()//高效算法
{
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= num;i++)
		for(int v = cost[i];v <= vo;v++)
			dp[v] = max(dp[v],dp[v - cost[i]] + value[i]);
}
*/

void DP()//转换为01 背包
{
	memset(dp,0,sizeof(dp));
	int tmp = num;
	for(int i = 1;i <= tmp;i++)
	{
		int extra = vo / cost[i];
		extra--;
		for(int j = 1;j <= extra;j++)
		{
			cost[num + 1] = cost[i];
			value[num + 1] = value[i];
			num++;
		}
	}

	for(int i = 1;i <= num;i++)
		for(int v = vo;v >= cost[i];v--)
			dp[v] = max(dp[v],dp[v - cost[i]] + value[i]);

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