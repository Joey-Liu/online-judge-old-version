#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 10 + 10;

struct Node
{
	int id;
	char str[maxn];
};

int cmp(Node a, Node b)
{
	return a.id < b.id;
}

char puzzle[maxn][maxn];
int ids[maxn][maxn];
Node nodes[150];
int R, C;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kase_num = 0;
	while ((cin >> R) && R)
	{
		cin >> C;
		int st_id = 1;
		memset(puzzle, -1, sizeof(puzzle));
		memset(ids, 0, sizeof(ids));
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> puzzle[i][j];



		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if ('*' != puzzle[i][j] && (!i || !j || '*' == puzzle[i][j - 1] || '*' == puzzle[i - 1][j]))
				{
					ids[i][j] = st_id;
					st_id++;
				}
			}
		}//for int i
		if (kase_num)
			printf("\n");
		cout << "puzzle #" << ++kase_num << ":" << endl;
		cout << "Across" << endl;
		for (int i = 0; i < R; i++)
		{
			int k = 0;
			while (k < C)
			{
				while(k < C && '*' == puzzle[i][k])
					k++;
				if (k < C)
				{
					printf("%3d.", ids[i][k]);
					while (k < C && '*' != puzzle[i][k])
					{
						printf("%c", puzzle[i][k]);
						k++;
					}
					printf("\n");
				}
			}//while k < C
		}//for int i

		memset(nodes, 0, sizeof(nodes));
		int cnt = 0;
		for (int j = 0; j < C; j++)
		{
			int k = 0;
			while (k < R)
			{
				while (k < R && '*' == puzzle[k][j])
					k++;
				if (k < R)
				{
					nodes[cnt].id = ids[k][j];
					int ind = 0;
					while (k < R && '*' != puzzle[k][j])
					{
						nodes[cnt].str[ind++] = puzzle[k][j];
						k++;
					}//while
					cnt++;
				}//if
			}//while k < R
		}//for int j
		sort(nodes, nodes + cnt, cmp);
		cout << "Down" << endl;
		for (int i = 0; i < cnt; i++)
			printf("%3d.%s\n", nodes[i].id, nodes[i].str);

	}//while

	return 0;
}