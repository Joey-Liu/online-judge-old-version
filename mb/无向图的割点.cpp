#include <iostream>
using namespace std;

const int maxn = 50;
int map[maxn][maxn];//均从零开始存储
int pa[maxn];//DFS 生成树
int adj[maxn];//结点入度,用于判断根节点
int pre[maxn];//访问时间
int low[maxn];//最早祖先发现时间
bool cut[maxn];//是否是 割点
int vi_time = 0;//结点访问时间

void init(int eg_num,int num_point)//边个数
{
	int m,n;
	for(int i = 0;i < eg_num;i++)
	{
		cin>>m>>n;
		m--;n--;
		map[m][n] = map[n][m] = 1;
	}
	//初始化访问时
	memset(pre,-1,sizeof(pre));
	memset(pa,-1,sizeof(pa));
	memset(adj,0,sizeof(adj));
	memset(cut,false,sizeof(cut));
}

// 将起始结点访问时间 和 最早发现祖先 设为 0
//从节点v开始 dfs 计算割点,fa 为v 结点的 父指针
//因为，在简单图中没有多重边，所以 使用父指针 避免产生 不存在的反向边
void find_cut_point(int v,int fa)
{
	pre[v] = low[v] = vi_time++;//设置访问时间 和 最早祖先 的初始值
	for(int w = 0;w < maxn;w++)
	{
		if(1==map[v][w] && v != w && w != fa)//依次搜索各边,防止产生自回路 和 不存在的反向边
		{
			if(-1==pre[w])//树边
			{
				pa[w] = v;//产生dfs 树
				adj[v]++;

				find_cut_point(w,v);
				if(low[w] >= pre[v])//v 是割点
					cut[v] = true;
				low[v] = min(low[v],low[w]);//计算最先发现祖先
			}
			else//反向边 ，调整最早 发现祖先
			{
				low[v] = min(low[v],pre[w]);
			}
		}//if 搜索各边
	}//for
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int node,edges;
	//cin>>node>>edges;
	while(cin>>node>>edges)
	{
		if(node || edges)
		{	
			init(edges,node);
			vi_time = 0;

			//从根开始 dfs
			//pre[1] = low[1] = vi_time;
			find_cut_point(5,-1);//根节点无父节点
			cut[5] = false;//根节点要单独判断

			if(adj[5] > 1)
				cut[5] = true;

			for(int i = 0;i < maxn;i++)
				if(cut[i])
					cout<<i<<" ";

			cout<<endl<<endl;
		}
		else
			break;
	}
	return 0;
}