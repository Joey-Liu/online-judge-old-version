#include <iostream>
#define MIN -1600000
using namespace std;

const int maxn = 10000 + 1000;
int value[550];
int weight[550];
int dp[maxn];
int E,F,N,vo;
int casenum;

void init()
{
	cin>>E>>F>>N;
	vo = F - E;
	for(int i = 1;i <= N;i++)
		cin>>value[i]>>weight[i];
}

void DP()
{
	for(int i = 1;i < maxn;i++)
		dp[i] = MIN;
	dp[0] = 0;

	for(int i = 1;i <= N;i++)
		for(int v = weight[i];v <= vo;v++)
		{
			int t1 = dp[v];
			int t2 = dp[v - weight[i]] + value[i];
			if(t1 >= 0 && t2 >= 0)
				dp[v] = min(dp[v],dp[v - weight[i]] + value[i]);
			else if(t1 >= 0 && t2 < 0)
				dp[v] = t1;
			else if(t1 < 0&& t2 >= 0)
				dp[v] = t2;
		}
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
		if(dp[vo] > 0)
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[vo]<<"."<<endl;
		else
			cout<<"This is impossible."<<endl;
	}//while
	return 0;
}