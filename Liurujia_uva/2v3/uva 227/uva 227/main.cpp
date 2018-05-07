#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 5;
char puzzle[maxn + 3][maxn + 3], order;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int pro, pcl;

bool in_puzzle(int r, int c)
{
	if (r >= maxn || r < 0 || c >= maxn || c < 0)
		return false;
	return true;
}


bool work(bool fa)
{
	if (!fa)
		return fa;

	int r, c, dire_num = 0;
	bool flag = true;
	if ('A' == order)
		dire_num = 0;
	else if ('B' == order)
		dire_num = 1;
	else if ('L' == order)
		dire_num = 2;
	else if ('R' == order)
		dire_num = 3;
	else
	{
		return false;
	}
	r = pro + dr[dire_num];
	c = pcl + dc[dire_num];
	if (in_puzzle(r, c))
	{
		swap(puzzle[pro][pcl], puzzle[r][c]);
		pro = r;
		pcl = c;
		return true;
	}
	else
		return false;
}//void work()

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 1;
	bool is_first = true;
	while (cin.get(puzzle[0][0]) && 'Z' != puzzle[0][0])
	{
		pro = 0, pcl = 0;
		for (int i = 1; i < maxn; i++)
		{
			cin.get(puzzle[0][i]);
			if (' ' == puzzle[0][i])
			{
				pro = 0;
				pcl = i;
			}
		}
		cin.get();
		for (int i = 1; i < maxn; i++)
		{
			for (int j = 0; j < maxn; j++)
			{
				cin.get(puzzle[i][j]);
				if (' ' == puzzle[i][j])
				{
					pro = i;
					pcl = j;
				}
			}
			cin.get();
		}
		bool flag = true;
		while (true)
		{
			cin >> order;
			if ('0' != order)
			{
				if (flag)
					flag = work(flag);
			}
			else
				break;
		}
		cin.get();
		if (is_first)
			is_first = false;
		else
			putchar('\n');
		printf("Puzzle #%d:\n", kasenum++);
		if(flag)
		{
			for (int i = 0; i < maxn; i++)
			{
				putchar(puzzle[i][0]);
				for (int j = 1; j < maxn; j++)
					printf(" %c", puzzle[i][j]);
				putchar('\n');
			}
		}
		else
			printf("This puzzle has no final configuration.\n");
		
	}//while
	return 0;
}