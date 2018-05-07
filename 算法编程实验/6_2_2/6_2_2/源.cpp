#include <iostream>
using namespace std;

const int maxn = 6000 + 1000;
int N;//节点个数;
int ra[maxn];//结点指数
int dp[maxn][2];//dp[i][0] 表示i不到时 的最大指数
int son[maxn];
int bro[maxn];
bool is_son[maxn];//构造树
int root;

void init()
{
	cin>>N;
	for(int i =1;i <= N;i++)
		cin>>ra[i];

	memset(son,0,sizeof(son));
	memset(bro,0,sizeof(bro));
	memset(is_son,false,sizeof(is_son));

	int k,L;
	for(int i = 1;i < N;i++)
	{
		cin>>L>>k;
		bro[L] = son[k];
		son[k] = L;
		is_son[L] = true;
	}

	for(int i = 1;i <= N;i++)
		if(!is_son[i])
		{
			root = i;
			break;
		}
}

void solve(int u)//计算 dp[u][0] dp[u][1]
{
	dp[u][0] = 0;
	dp[u][1] = ra[u];

	int s;
	for(s = son[u];s != 0;s = bro[s])
	{
		solve(s);
		dp[u][0] += max(dp[s][0],dp[s][1]);
		dp[u][1] += dp[s][0];
	}
}


int main()
{
	freopen("10","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	solve(root);
	cout<<max(dp[root][0],dp[root][1])<<endl;
	return 0;
}