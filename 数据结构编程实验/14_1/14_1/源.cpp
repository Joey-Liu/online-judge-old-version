#include <iostream>
using namespace std;

const int maxn = 1000 + 100;
bool map[maxn][maxn];
int visited[maxn];
int pre[maxn];//匹配边集

int m,n;//两集合节点个数

bool dfs(int i)//从x集合i结点 寻找增广路径
{
	for(int j = 1;j <= n;j++)
	{
		if(!visited[j] && map[i][j])
		{
			visited[j] = true;
			if(pre[j]==0 || dfs(pre[j]))
			{
				pre[j] = i;
				return true;
			}//if pre[j]
		}
	}
	return false;//未找到增广路径
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(map,false,sizeof(map));
	int edge;
	cin>>m>>n>>edge;
	int a,b;
	for(int i = 0;i < edge;i++)
	{
		cin>>a>>b;
		map[a][b] = map[b][a] = true;
	}

	int res = 0;
	for(int i = 1;i <= m;i++)//枚举x集合中的每个节点
	{
		memset(visited,false,sizeof(visited));
		if(dfs(i))
			res++;
	}
	cout<<m + n - res<<endl;
	return 0;
}