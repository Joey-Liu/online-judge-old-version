#include <iostream>
using namespace std;

const int maxn = 100;
int map[maxn][maxn];
int pre[maxn];//入度
bool has[maxn];//是否排序
int order[maxn];//拓扑序列

int edge_num;//边的数量
int node_num;

int dp[maxn];//dp[i] 从源节点 到i节点的 最长路径长度
int parent[maxn];//节点i的前驱节点

void init()
{
	int one,two,weight;
	memset(pre,0,sizeof(pre));
	memset(map,0,sizeof(map));

	for(int i = 0;i < edge_num;i++)
	{
		cin>>one>>two>>weight;
		map[one][two] = weight;
		pre[two]++;
	}
	memset(has,false,sizeof(has));
	memset(dp,-1,sizeof(dp));

}


void topo(int dep)//首次调用时dep = 1 order[1---node_num]
{
	for(int i = 1;i < maxn && dep <= node_num;i++)
	{
		if(!has[i] && pre[i]==0)
		{
			has[i] = true;
			order[dep] = i;
			for(int k = 1;k < maxn;k++)
			{
				if(map[i][k] != 0)
					pre[k]--;
			}
			dep++;
			i = 0;
			if(dep > node_num)
				break;
		}
	}
}

void solve()
{
	memset(parent,0,sizeof(parent));
	memset(dp,0,sizeof(dp));

	for(int i = 1;i <= node_num;i++)//自底向上求最子问题
	{
		for(int j = 1;j < maxn;j++)
		{
			if(map[j][order[i]])
			{
				if(dp[order[i]] < dp[j] + map[j][order[i]])
				{
					dp[order[i]] = dp[j] + map[j][order[i]];
					parent[order[i]] = j;
				}
			}
		}//for int j
	}//for int i
}

void print(int n)
{
	if(parent[n] != 0)
		print(parent[n]);
	cout<<n<<" ";
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int goal;
	while(cin>>node_num>>edge_num)
	{
		init();
		topo(1);
		solve();
		cin>>goal;
		print(goal);
		cout<<endl;
	}
	return 0;
}