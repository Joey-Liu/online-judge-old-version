#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 10000 + 100;
int start[maxn];//儿子节点在 儿子序列中的开始位置
int ele[maxn];//儿子序列 基于0
int tot[maxn];//结点及子树的 弹子总数
int child[maxn];//结点儿子数量
bool fa[maxn];//父节点标示

//看了大概思路，应该是用贪心思想，如果求最小移动数量，应该让子树移动数量最小
//而 子树移动最小数量为 子树节点数量 - 子树弹子数
//号码基于1，fa ，ele 

int cnt = 0;

void init(int node_num)
{
	cnt = 0;

	memset(fa,false,sizeof(fa));
	int v;//结点编号
	for(int i = 0;i < node_num;i++)
	{
		cin>>v;
		cin>>tot[v];
		cin>>child[v];
		start[v] = cnt;//儿子结点在 ele表中开始位置
		for(int j = 0;j < child[v];j++)
		{
			int tmp;
			cin>>tmp;
			ele[cnt++] = tmp;
			fa[tmp] = true;
		}
	}
}

int dfs(int c,bool flag)//从节点c开始后跟遍历
{
	int res = 0;
	for(int i = 0;i < child[c];i++)
		res += dfs(ele[ start[c] + i ] ,false);//依次遍历各个儿子

	//统计自身情况
	int limit = child[c];
	for(int i = 0;i < limit;i++)
	{
		child[c] += child[ ele[start[c] + i] ]; //对儿子数量进行更新
		tot[c] += tot[ele [start[c] + i ] ];
	}

	//if(flag==false)
	res += abs(tot[c] - (child[c] + 1));
	return res;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(cin>>n && n != 0)
	{
		init(n);
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(!fa[i])
			{
				ans += dfs(i,true);
			}
		}

		cout<<ans<<endl;
	}//while
	return 0;
}