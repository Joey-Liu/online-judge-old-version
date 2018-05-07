#include <cstdio>
#include <memory.h>
#include <vector>

using namespace std;
const int maxn = 100 + 5;
int parent[maxn];
int layer[maxn];
vector<int> son[maxn];//存储孩子结点
bool path[maxn];

void DFS(int node,int dep)//递归设置各个节点层次
{
	layer[node] = dep;
	for(vector<int> ::iterator it = son[node].begin();it != son[node].end();it++)
		DFS(*it,dep + 1);
}

int find(int a,int b)//返回a，b的共同祖先
{
	while(a != b)
	{
		path[a] = true;
		path[b] = true;//标记路径
		if(layer[a] > layer[b])
			a = parent[a];
		else
			b= parent[b];
	}
	return a;//共同祖先
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i = 0;i < n;i++)	
			son[i].clear();//每个儿子节点初始化为空
		memset(parent,-1,sizeof(parent));//父母结点初始化为-1

		int u,v;
		for(i = 0;i < n - 1;i++)
		{
			scanf("%d%d",&u,&v);
			u--;v--;////////////
			son[u].push_back(v);
			parent[v] = u;
		}
		
		for(i = 0;parent[i] > 0;i++)
			;//找到根节点
		DFS(i,0);//设置各个节点层次
		
		int m;
		scanf("%d",&m);//m个询问

		for(i = 0;i < m;i++)//应该把每个路径设为FALSE
		{
			memset(path,false,sizeof(path));
			int x ,y ,z;
			scanf("%d %d %d",&x,&y,&z);
			x--;y--;z--;

			int pre = find(y,z);
			
			int root = x;//建立新的路径,从COM到root，看root是否 会访问标记路径
			int com = y;
			bool flag = false;
			bool apend = false;

			if(root == y || root == z)//如果根与 任意一节点相同，那么祖先就是根节点
			{
				flag =true;
				apend = true;
			}

			while(root != com && apend == false)//当根节点 与 y，z 无直接联系时，进行路径回溯
			{
				if(layer[root] > layer[com])
				{
					root = parent[root];
					if(true==path[root])
					    {flag = true;break;}
				}
				else
					com = parent[com];	
			}
			if(true==flag)//////////////////////////////
				printf("%d\n",root + 1);//共同祖先
			else
				printf("%d\n",pre + 1);//原共同祖先
		}
	}//while
	return 0;
}