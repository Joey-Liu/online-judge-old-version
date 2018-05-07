#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <queue>

using namespace std;
const int maxn = 30 * 4;
int level, rows, cols, gl,  gr, gc,sl, sr, sc;
char dungeon[maxn][maxn][maxn];
bool visited[maxn][maxn][maxn];
int steps[maxn][maxn][maxn];
bool success = false;
int dires[6][3] = { { -1, 0, 0 }, { 1, 0, 0 }, { 0, 1, 0 }, {0, -1, 0},
{ 0, 0, 1 }, {0, 0, -1} };

struct Node
{
	int nl, nr, nc;
	Node(int l, int r, int c)
	{
		nl = l;
		nr = r;
		nc = c;
	}
};

bool inDungeon(int l, int r, int c)
{
	if (l >= level || l < 0 || r >= rows || r < 0 || c >= cols || c < 0)
		return false;
	return true;
}

bool bfs()
{
	queue<Node> qn;
	qn.push(Node(sl, sr, sc));
	steps[sl][sr][sc] = 0;

	while (!qn.empty() && !success)
	{
		Node tn = qn.front();
		qn.pop();
		if (tn.nl == gl && tn.nr == gr && tn.nc == gc)
		{
			success = true;
			break;
		}
		int stepnow = steps[tn.nl][tn.nr][tn.nc];

		int tml, tmr, tmc;
		for (int i = 0; i < 6; i++)
		{
			tml = tn.nl + dires[i][0];
			tmr = tn.nr + dires[i][1];
			tmc = tn.nc + dires[i][2];
			if (inDungeon(tml, tmr, tmc) && !visited[tml][tmr][tmc] && ('.' == dungeon[tml][tmr][tmc] || 'E' == dungeon[tml][tmr][tmc]))
			{
				visited[tml][tmr][tmc] = true;
				qn.push(Node(tml, tmr, tmc));
				steps[tml][tmr][tmc] = stepnow + 1;
			}
		}
	}//while

	if (!success)
		return false;
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (3 == scanf("%d%d%d", &level, &rows, &cols))
	{
		getchar();
		if (!level && !rows && !cols)
			break;
		for (int i = 0; i < level; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				gets(dungeon[i][j]);
				char *st = strchr(dungeon[i][j], 'S');
				if (NULL != st)
				{
					sl = i;
					sr = j;
					sc = st - dungeon[i][j];
				}
				char *ed = strchr(dungeon[i][j], 'E');
				if (NULL != ed)
				{
					gl = i;
					gr = j;
					gc = ed - dungeon[i][j];
				}
			}
			getchar();
		}
		memset(steps, -1, sizeof(steps));
		memset(visited, false, sizeof(visited));
		success = false;

		bfs();
		if (!success)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", steps[gl][gr][gc]);
	}
	return 0;
}