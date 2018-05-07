#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1001;
//n1,n2Ϊ����ͼ�Ķ��㼯,����x��n1,y��n2
int map[N][N], vis[N], cx[N], cy[N];
//link��¼n2�еĵ�y��n1����ƥ���x��ı��
int num;

int path(int u)
{
	int v;
	for (v = 0; v < num; v++)
	{
		if (map[u][v] && !vis[v])
		{
			vis[v] = 1;
			if (cy[v] == -1 || path(cy[v]))//���y�����е�vԪ��û��ƥ�������v�Ѿ�ƥ�䣬���Ǵ�cy[v]���ܹ��ҵ�һ������·    
			{
				cx[u] = v; //�ҵ�����·���޸�ƥ��M    
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
		if (cx[i] == -1)   //��û��ƥ�䣬ִ���ڲ�����    
		{
			memset(vis, 0, sizeof(vis));  //���ñ��ΪΪ����    
			res += path(i);   //�� i Ϊ��㿪ʼ��������·������true ��ƥ����+1    
		}
	}
	printf("%d\n", res);
	return 0;
}