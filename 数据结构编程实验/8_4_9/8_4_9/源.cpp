#include <iostream>
#include <vector>
#include <stdio.h>
#include <memory.h>
using namespace std;

const int maxn = 1000 + 500;
bool valid[maxn];//树根标志
bool visited[maxn];//访问标志
vector<int> c[maxn];//儿子节点
vector<int> q[maxn];//询问

int set[maxn];//并查集
int ancestor[maxn];//祖先
int ans[maxn];//以结点i为共同祖先的询问数

int set_find(int p)
{
	if(set[p] < 0)
		return p;
	return set[p] = set_find(set[p]);
}

void join(int p,int q)//p加入q
{
	p = set_find(p);
	q = set_find(q);
	if(p != q)
		set[p] = q;
}

void LCA(int u)
{
	set[u] = -1;//先将自己形成一个集合
	ancestor[u] = u;
	int size = c[u].size();
	for(int i =0;i < size;i++)
	{
		LCA(c[u][i]);//依次对子节点进行处理
		join(c[u][i],u);//把子节点集合加入到父节集合点中
		ancestor[set_find(u)] = u;//确保这个集合的祖先不发生改变
	}
	visited[u] = true;
	size = q[u].size();
	for(int i =0;i < size;i++)
	{
		if(visited[q[u][i]])//如果已经访问过了问题i的结点 那么就可以直接返回答案，否则等到该问题结点被遍历时在进行返回
		{
			ans[set_find(q[u][i])]++;//集合的祖先即为共同祖先
		}//应该只会统计一次
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num;//结点个数
	while(1==scanf("%d",&num))
	{
		memset(valid,false,sizeof(valid));//root判断
		memset(visited,false,sizeof(visited));
		for(int i = 0;i < num;i++)
		{
			c[i].clear();
			q[i].clear();
			ans[i] = 0;
		}
		memset(set,-1,sizeof(set));
		memset(ancestor,-1,sizeof(ancestor));
		
		for(int i = 0;i < num;i++)
		{
			int x,y,tmp;
			scanf("%d:(%d)",&x,&y);
			for(int j = 0;j < y;j++)
			{
				scanf("%d",&tmp);
				valid[tmp -1] = true;
				c[x -1].push_back(tmp - 1);
			}
		}
		int qnum;
		scanf("%d",&qnum);
		//处理询问
		for(int i = 0;i < qnum;i++)
		{
			int a,b;
			char c;
			while(scanf("%c",&c) && c != '(');
			scanf("%d,%d",&a,&b);
			while(scanf("%c",&c) && c != ')');
			//相当于询问两次
			a--;b--;
			q[a].push_back(b);
			q[b].push_back(a);
		}
		for(int i = 0;i < num;i++)
		{
			if(!valid[i])
			{
				LCA(i);
				break;
			}
		}

		for(int i = 0;i < num;i++)
		{
			if(ans[i] > 0)
				printf("%d:%d\n",i + 1,ans[i]);
		}
	}//while
	return 0;
}