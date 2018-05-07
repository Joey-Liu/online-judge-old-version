#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 110;//歹徒人数
const int maxopen = 100;//门打开程度
struct men
{
	int ti;//歹徒到来时间
	int pro;//歹徒繁荣度
	int sto;//歹徒胖瘦
}g[maxn];

int K;//饭店状态范围
int T;//时间范围
int N;//歹徒人数 
int dp[maxn];//dp[i]第i个人进入饭店的最大繁荣值

int cmp(const void* a,const void* b)
{
	men* _a = (men *)a;
	men* _b = (men *)b;
	return (_a->ti - _b->ti);
}

void solve()
{
	for(int i = 0;i < N;i++)
	{
		if(g[i].sto <= g[i].ti)
			dp[i] = g[i].pro;//最大繁荣值初始化
		else
		{
			dp[i] = 0;//根本不会让他进来，繁荣值为0；
			continue;
		}

		for(int j = 0;j < i;j++)//枚举产生最优解
		{
			if(abs(g[i].ti - g[j].ti) >= abs(g[i].sto - g[j].sto) )
				dp[i] = max(dp[i],dp[j] + g[i].pro);
		}
	}//for int i
	int res = 0;
	for(int i = 0;i < N;i++)
	{
		if(res < dp[i])
			res = dp[i];
	}
	cout<<res<<endl;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>N>>K>>T;
	
	for(int i = 0;i < N;i++)
		cin>>g[i].ti;
	for(int i = 0;i < N;i++)
		cin>>g[i].pro;
	for(int i = 0;i < N;i++)
		cin>>g[i].sto;

	qsort(g,N,sizeof(g[0]),cmp);
	memset(dp,-1,sizeof(dp));
	solve();

	return 0;
}