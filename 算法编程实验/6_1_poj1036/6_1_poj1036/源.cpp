#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 110;//歹徒人数
const int maxtime = 3000;//时间
const int maxopen = 100;//门打开程度
struct men
{
	int ti;//歹徒到来时间
	int pro;//歹徒繁荣度
	int sto;//歹徒胖瘦
}g[maxn];

int K;//饭店状态范围
int T;//时间范围
int N;//歹徒人数 0-N!!!!!!!!!!!!!!!!!!!!!////////////////////
int dp[maxtime][maxopen][maxn];//dp 在i时刻 门打开程度为 j 时 处理 k 个歹徒 的最大繁荣度

int solve(int time,int open,int num) // 0-num名歹徒
{
	int ret = 0;
	if(dp[time][open][num] != -1)
		ret = dp[time][open][num];
	else
	{
		//边界条件
		if(num == 0)//处理到最后一名歹徒
		{
			if(abs(g[N - num].sto - open) <= abs(g[N - num].ti - time))
				ret = g[N - num].pro;
		}
		else
		{
			if(abs(g[N - num].sto - open) <= abs(g[N - num].ti - time) )//如果目前歹徒N -num可以进入饭店
			{
				ret = max(solve(g[N -num].ti,g[N - num].sto,num - 1) + g[N - num].pro , solve(time,open,num - 1));
			}//歹徒可以进入饭店
			else
				ret = solve(time,open,num - 1);
		}
	}//if dp[][][] == -1

	dp[time][open][num] = ret;
	return ret;
}

int cmp(const void* a,const void* b)
{
	men* _a = (men *)a;
	men* _b = (men *)b;
	return (_a->ti - _b->ti);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>N>>K>>T;
	N--;//N+1个歹徒
	
	for(int i = 0;i <= N;i++)
		cin>>g[i].ti;
	for(int i = 0;i <= N;i++)
		cin>>g[i].pro;
	for(int i = 0;i <= N;i++)
		cin>>g[i].sto;

	qsort(g,N + 1,sizeof(g[0]),cmp);
	memset(dp,-1,sizeof(dp));

	cout<<solve(0,0,N)<<endl;

	return 0;
}