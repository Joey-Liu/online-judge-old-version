#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
const int maxn = 10 + 10;

bool checked[maxn][maxn];
char cmap[maxn][maxn];

int pieces, black_grow, black_gcol;
int horse_dr[] = { 1,-1, -2, -2, -1, 1, 2, 2 };
int horse_dc[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int horse_leg_dr[] = {0, -1, 0, 1};
int horse_leg_dc[] = { -1, 0, 1, 0 };
int piv_row, piv_col;

struct Node
{
	char ch;
	int r, c;
}nodes[maxn];

bool in_map(int r, int c)
{
	if (r < 1 || r > 10 || c < 1 || c > 9)
		return false;
	return true;
}

bool in_tent(int r, int c)
{
	if (r < 1 || r > 3 || c < 4 || c > 6)
		return false;
	return true;
}

void label_line(int r, int c, int dir)
{
	int line_dr[] = { -1, 0, 1, 0 };
	int line_dc[] = { 0, 1, 0, -1 };
	int rr = r + line_dr[dir], cc = c + line_dc[dir];
	while (in_map(rr, cc) && !cmap[rr][cc])
	{
		checked[rr][cc] = true;
		rr = rr + line_dr[dir];
		cc = cc + line_dc[dir];
	}
}

void find_pivot(int r, int c, int dir)
{
	int line_dr[] = { -1, 0, 1, 0 };
	int line_dc[] = { 0, 1, 0, -1 };
	int rr = r + line_dr[dir], cc = c + line_dc[dir];
	while (in_map(rr, cc) && !cmap[rr][cc])
	{
		rr = rr + line_dr[dir];
		cc = cc + line_dc[dir];
	}
	piv_row = rr;
	piv_col = cc;
}

void check_piece(char ch, int r, int c)
{
	if ('G' == ch || 'R' == ch)
	{
		for (int i = 0; i < 4; i++)
			label_line(r, c, i);
	}
	else if ('H' == ch)
	{
		for (int i = 0; i < 8; i++)
		{
			int dr = r + horse_dr[i], dc = c + horse_dc[i];
			int leg_dr = r + horse_leg_dr[i / 2], leg_dc = c + horse_leg_dc[i / 2];
			if (in_map(dr, dc) && '\0' == cmap[leg_dr][leg_dc])
				checked[dr][dc] = true;
		}
	}//else if
	else if ('C' == ch)
	{
		for (int i = 0; i < 4; i++)
		{
			find_pivot(r, c, i);
			label_line(piv_row, piv_col, i);
		}
	}//else if 
}

bool work()
{
	for (int i = 0; i < pieces; i++)
		check_piece(nodes[i].ch, nodes[i].r, nodes[i].c);
	int dr[] = { -1, 0, 1, 0 };
	int dc[] = { 0, 1, 0, -1 };
	bool flag = false;
	for (int i = 0; i < 4; i++)
	{
		int r = black_grow + dr[i];
		int c = black_gcol + dc[i];
		if (in_tent(r, c) && !checked[r][c])
			flag = true;
	}
	return flag;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (3 == scanf("%d%d%d", &pieces, &black_grow, &black_gcol))
	{
		memset(checked, false, sizeof(checked));
		memset(cmap, 0, sizeof(cmap));
		memset(nodes, 0, sizeof(nodes));
		if (!pieces && !black_grow && !black_gcol)
			break;
		for (int i = 0; i < pieces; i++)
		{
			getchar();
			scanf("%c%d%d", &nodes[i].ch, &nodes[i].r, &nodes[i].c);
			cmap[nodes[i].r][nodes[i].c] = nodes[i].ch;
		}
		bool flag = work();
		bool fly_gen = false;
		for (int gen_row = black_grow + 1; gen_row <= 10; gen_row++)
		{
			if (cmap[gen_row][black_gcol])
			{
				if('G' == cmap[gen_row][black_gcol])
					fly_gen = true;
				break;
			}
		}
		const char* str = (flag || fly_gen ? "NO" : "YES");
		printf("%s\n", str);
	}//while
	return 0;
}