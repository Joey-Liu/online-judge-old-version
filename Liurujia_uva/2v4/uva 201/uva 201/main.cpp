#include <iostream>
#include <memory.h>
using namespace std;
const int maxn = 9 + 9;

struct Node
{
	bool direct[4];
	Node()
	{
		for (int i = 0; i < 4; i++)
			direct[i] = false;
	}
};

int N, M;
char edge_type[maxn];
Node grid[maxn][maxn];
int square_num[maxn];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool edge_exist(int r, int c, int edge_length, int direct_index)
{
	bool flag = true;
	for (int i = 0; i < edge_length; i++)
	{
		if (!grid[r][c].direct[direct_index])
		{
			flag = false;
			break;
		}
		r = r + dr[direct_index];
		c = c + dc[direct_index];
	}
	return flag;
}

int work(int edge_length)
{
	int res = 0;
	for (int i = 1; i <= N - edge_length; i++)
	{
		for (int j = 1; j <= N - edge_length; j++)
		{
			bool flag[4] = { false };
			flag[0] = edge_exist(i, j, edge_length, 1);
			flag[1] = edge_exist(i, j, edge_length, 2);
			flag[2] = edge_exist(i, j + edge_length, edge_length, 2);
			flag[3] = edge_exist(i + edge_length, j, edge_length, 1);
			if (flag[0] && flag[1] && flag[2] && flag[3])
				res++;
		}
	}//for int i
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	bool first = true;
	while (1 == scanf("%d", &N))
	{
		if (!first)
			printf("\n**********************************\n\n");
		first = false;
		scanf("%d", &M);
		memset(grid, false, sizeof(grid));
		memset(square_num, 0, sizeof(square_num));
		for (int i = 0; i < M; i++)
		{
			int a, b;
			scanf("%s%d%d", edge_type, &a, &b);
			if ('H' == edge_type[0])
			{
				grid[a][b].direct[1] = true;
				grid[a][b + 1].direct[3] = true;
			}
			else
			{
				grid[b][a].direct[2] = true;
				grid[b + 1][a].direct[0] = true;
			}
		}//for int i
		
		int flag = false;
		for (int edge_length = 1; edge_length <= M; edge_length++)
		{
			square_num[edge_length] = work(edge_length);
			if (square_num[edge_length])
				flag = true;
		}
		printf("Problem #%d\n\n", ++kasenum);
		if (flag)
		{
			for (int i = 1; i <= N; i++)
			{
				if (square_num[i])
					printf("%d square (s) of size %d\n", square_num[i], i);
			}
		}
		else
			printf("No completed squares can be found.\n");

	}//while
	return 0;
}