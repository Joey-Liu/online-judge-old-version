#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

const int maxn = 100 + 20;

char today[maxn][maxn];
char tommo[maxn][maxn];

int kase, row, col, days;
int rd[] = {-1 , 0, 1, 0};
int cd[] = { 0, 1, 0, -1 };


bool isLegal(int r, int c)
{
	if (r < 0 || c < 0 || r >= row || c >= col)
		return false;
	return true;
}

void conq(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		int rp = r + rd[i];
		int cp = c + cd[i];
		if (isLegal(rp, cp))
		{
			if ('R' == today[r][c] && today[rp][cp] == 'S')
				tommo[rp][cp] = 'R';
			else if ('S' == today[r][c] && today[rp][cp] == 'P')
				tommo[rp][cp] = 'S';
			else if ('P' == today[r][c] && today[rp][cp] == 'R')
				tommo[rp][cp] = 'P';
		}
	}//for
}

void solve()
{
	memset(tommo, 0, sizeof(tommo));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			conq(i, j);
		}
	}//for
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (tommo[i][j] == 0)
				tommo[i][j] = today[i][j];
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &kase);
	for (int kasecount = 0; kasecount < kase; kasecount++)
	{
		if (kasecount != 0)
			printf("\n\n");
		scanf("%d%d%d", &row, &col, &days);
		getchar();
		for (int i = 0; i < row; i++)
			gets(today[i]);
		
		for (int i = 0; i < days; i++)
		{
			solve();
			memcpy(today, tommo, sizeof(today));
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				printf("%c", today[i][j]);
			}
			if (i != row - 1)
				printf("\n");
		}
	}

	return 0;
}