#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1001;
//n1,n2为二分图的顶点集,其中x∈n1,y∈n2
int map[N][N], vis[N], cx[N], cy[N];
//link记录n2中的点y在n1中所匹配的x点的编号
int num;

int path(int u)
{
	int v;
	for (v = 0; v < num; v++)
	{
		if (map[u][v] && !vis[v])
		{
			vis[v] = 1;
			if (cy[v] == -1 || path(cy[v]))//如果y集合中的v元素没有匹配或者是v已经匹配，但是从cy[v]中能够找到一条增广路    
			{
				cx[u] = v; //找到增广路，修改匹配M    
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

struct Node
{
	int x, y;
	Node(int a = -1, int b = -1)
	{
		x = a;
		y = b;
	}
};

vector<Node> vx, vy;

void init()
{
	scanf("%d", &num);
	for (int i = 0; i <  num; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		vx.push_back(Node(a, b));
	}
	for (int i = 0; i < num; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		vy.push_back(Node(a, b));
	}

	memset(vis, false, sizeof(vis));
	memset(map, 0, sizeof(map));
	memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (vx[i].x < vy[j].x && vx[i].y < vy[j].y)
			{
				map[i][j] = 1;
			}
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	init();
	int res = 0;
	for (int i = 0; i < num; i++)
	{
		if (cx[i] == -1)   //还没被匹配，执行内部代码    
		{
			memset(vis, 0, sizeof(vis));  //重置标记为为访问    
			res += path(i);   //以 i 为起点开始查找增广路，返回true ，匹配数+1    
		}
	}
	printf("%d\n", res);
	return 0;
}