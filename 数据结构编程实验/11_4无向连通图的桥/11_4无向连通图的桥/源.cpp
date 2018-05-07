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
	memset(map,0,sizeof(map));
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

void find_bridge(int v,int fa)
{
	pre[v] = low[v] = vi_time++;//初始化访问时间和 最早祖先
	for(int w = 0;w < maxn;w++)
	{
		if(1==map[v][w] && v != w && w != fa)
		{
			if(-1==pre[w])//如果v-w 为树枝边
			{
				find_bridge(w,v);
				if(low[w]==pre[w] || low[w] > pre[v] )
					cout<<v<<"-"<<w<<endl;
				low[v] = min(low[v],low[w]);
			}
			else//反向边
				low[v] = min(low[v],pre[w]);
		}// if map==1
	}//for int w
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int node,edges;
	while(cin>>node>>edges)
	{
		if(node || edges)
		{	
			init(edges,node);
			vi_time = 0;

			//从零开始 dfs
			pre[0] = low[0] = vi_time;
			
			find_bridge(0,-1);
			cout<<endl<<endl;
		}
		else
			break;
	}
	return 0;
}