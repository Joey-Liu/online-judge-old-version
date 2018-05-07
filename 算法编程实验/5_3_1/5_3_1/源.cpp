#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 1000 + 100;
int root;
int n;//节点数量
int parent[maxn];//父节点
int nex[maxn];//染色顺序
int cnt[maxn];//结点个数
int c[maxn];//染色费用
int v[maxn][maxn];//邻接矩阵

double ave[maxn];//每个节点平均染色费用

void init()
{
	int x,y;
	memset(v,0,sizeof(v));
	for(int i = 1;i <= n;i++)
		cin>>c[i];
	for(int i = 1;i < n;i++)
	{
		cin>>x>>y;
		v[x][++v[x][0]] = y;
		v[y][++v[y][0]] = x;
	}
}

void DFS(int x)
{
	int tmp;
	for(int i =1;i <= v[x][0];i++)
	{
		tmp = v[x][i];
		if(0==parent[tmp])
		{
			parent[tmp] = x;
			DFS(tmp);
		}
	}
}

void addedge(int x,int y)//把y放在x的染色顺序后
{
	while(nex[x])
	{
		x = nex[x];
	}
	nex[x] = y;
}

void solve()
{
	memset(parent,0,sizeof(parent));
	parent[root] = -1;
	DFS(root);//以root为根建立父指针

	for(int i = 1;i <= n;i++)
	{
		ave[i] = c[i];//结点平均值初始化
		cnt[i] = 1;
	}
	bool flag[maxn];//节点是否已经被处理过,true 为还未处理
	memset(flag,true,sizeof(flag));
	memset(nex,0,sizeof(nex));
	int tmp;

	for(int count = 1;count < n;count++)//进行n-1次节点处理
	{
		double maxp = 0;//wa 了好久
		for(int i =1;i <= n;i++)
		{
			if((flag[i]) && (ave[i] > maxp) && (i != root))//结点尚未处理且平均值高,注意i ！=root
			{
				maxp = ave[i];
				tmp = i;
			}
		}
		int fa = parent[tmp];
		addedge(fa,tmp);//把tmp加入fa的顺序中
		//对fa结点及以上结点造成影响，实际上就是对还未进行处理的结点平均染色质的影响
		while(!flag[fa])
			fa = parent[fa];

		flag[tmp] = false;
		//对节点平均染色值 和合并节点数进行更新
		ave[fa] = (cnt[fa] * ave[fa]  +  cnt[tmp] * ave[tmp])/(cnt[fa] + cnt[tmp]);
		cnt[fa] += cnt[tmp];

	}//for int count
	
	long long int res = 0;
	tmp = root;
	for(int i = 1;i <= n;i++)
	{
		res += i * c[tmp];
		tmp = nex[tmp];
	}
	cout<<res<<endl;
}//solve

int main()
{
	freopen("color.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>n>>root;
	while(n || root)
	{
		init();
		solve();
		cin>>n>>root;
	}
	return 0;
}