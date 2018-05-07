#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10000 + 100;

vector<int> child[maxn];//儿子节点

int parent[maxn];//节点父指针
int layer[maxn];//检点层次
void DFS(int i,int n)			//深度遍每个节点深度历
{
	layer[i] = n;
	for(vector<int>::iterator ptr = child[i].begin();ptr != child[i].end();ptr++)
		DFS(*ptr,n + 1);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int casetime;
	cin>>casetime;
	while(casetime--)
	{
		int node_num;
		cin>>node_num;
		memset(parent,-1,sizeof(parent));
		for(int i =0;i < node_num;i++)
			child[i].clear();
		
		int a,b;
		for(int i = 0;i < node_num - 1;i++)
		{
			cin>>a>>b;
			a--;b--;
			child[a].push_back(b);
			parent[b] = a;				//设置父子指针信息
		}
		int i;
		for(i = 0;parent[i] >= 0;i++)
			;//找到根节点
		DFS(i,0); 

		int x,y;
		cin>>x>>y;
		x--;y--;
		while (x != y)
		{
			if(layer[x] > layer[y])
				x = parent[x];
			else
				y = parent[y];
		}
		cout<<x + 1<<endl;
	}
	system("pause");
	return 0;
}