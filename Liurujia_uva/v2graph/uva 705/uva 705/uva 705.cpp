#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory>

using namespace std;
const int maxn = 100 * 3;
int mp[maxn][maxn];
char str[maxn];
int kasenum = 0, width, height;
int dire[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
bool flag = true;
int cnt = 0, cyclenum = 0;

bool inmp(int r, int c)
{
	if (r < 0 || r >= 3 * height || c < 0 || c >= 3 * width)
		return false;
	return true;
}

void dfs(int r, int c)
{
	cnt++;
	mp[r][c] = 1;
	if (r == 0 || r == 3 * height - 1 ||
		c == 0 || c == 3 * width - 1)
	{
		flag = false;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dire[i][0];
		int nc = c + dire[i][1];
		if (inmp(nr, nc) && !mp[nr][nc])
			dfs(nr, nc);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (2 == scanf("%d%d", &width, &height))
	{
		memset(mp, 0, sizeof(mp));
		if (0 == width && 0 == height)
			break;
		if (kasenum)
			printf("\n");
		for (int i = 0; i < height; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < width; j++)
			{
				if ('\\' == str[j])
				{
					mp[i * 3][j * 3] = 1;
					mp[i * 3 + 1][j * 3 + 1] = 1;
					mp[i * 3 + 2][j * 3 + 2] = 1;
				}
				else
				{
					mp[i * 3][j * 3 + 2] = 1;
					mp[i * 3 + 1][j * 3 + 1] = 1;
					mp[i * 3 + 2][j * 3] = 1;
				}
			}
		}//for int i
		cyclenum = 0;
		int longestlen = -1;
		for (int i = 0; i < height * 3; i++)
		{
			for (int j = 0; j < width * 3; j++)
			{
				if (0 == mp[i][j])
				{
					flag = true;
					cnt = 0;
					dfs(i, j);
					if (flag)
					{
						cyclenum++;
						if (cnt / 3 > longestlen)
							longestlen = cnt / 3;
					}
				}
			}
		}//for int i
		printf("Maze #%d\n", ++kasenum);
		if (!cyclenum)
			printf("There are no cycles.\n");
		else
			printf("%d Cycles; the longest has length %d.\n", cyclenum, longestlen);
	}//while
	return 0;
}