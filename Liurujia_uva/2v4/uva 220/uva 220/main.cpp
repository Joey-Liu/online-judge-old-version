#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 8 + 5;

char board[maxn][maxn], cmd[maxn];

int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1 ,0, -1, -1, -1 };
int black_num, white_num;

bool in_board(int r, int c)
{
	if (r < 0 || r > 7 || c < 0 || c > 7)
		return false;
	return true;
}

bool set_disk(int r, int c, char ch)
{
	bool flag = false;
	if (board[r][c] != '-')
		return false;
	for (int i = 0; i < 8; i++)
	{
		bool op_exist = false;
		int pr = r + dr[i];
		int pc = c + dc[i];
		while (in_board(pr, pc) && board[pr][pc] != '-' && board[pr][pc] != ch)
		{
			op_exist = true;
			pr = pr + dr[i];
			pc = pc + dc[i];
		}
		if (op_exist && in_board(pr, pc) && ch == board[pr][pc])
		{
			flag = true;
			break;
		}
	}//for
	return flag;
}

void move_disk(int r, int c, char ch)
{
	board[r][c] = ch;
	for (int dir = 0; dir < 8; dir++)
	{
		int pr = r + dr[dir];
		int pc = c + dc[dir];
		bool op_exist = false;
		while (in_board(pr, pc) && board[pr][pc] != '-' && board[pr][pc] != ch)
		{
			op_exist = true;
			pr = pr + dr[dir];
			pc = pc + dc[dir];
		}
		if (op_exist && in_board(pr, pc) && ch == board[pr][pc])
		{
			pr = r + dr[dir];
			pc = c + dc[dir];
			while (board[pr][pc] != ch)
			{
				board[pr][pc] = ch;
				pr = pr + dr[dir];
				pc = pc + dc[dir];
			}
		}
	}
}

void check_disk()
{
	black_num = 0;
	white_num = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ('B' == board[i][j])
				black_num++;
			else if ('W' == board[i][j])
				white_num++;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	bool isFirst = true;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		if (!isFirst)
			printf("\n");
		isFirst = false;
		black_num = 0;
		white_num = 0;
		for (int i = 0; i < 8; i++)
			scanf("%s", board[i]);
		scanf("%s", cmd);
		char players[] = { 'B', 'W' };
		int pl = (cmd[0] == 'B' ? 0 : 1);
		while (scanf("%s", cmd) && 'Q' != cmd[0])
		{
			if ('L' == cmd[0])
			{
				bool flag = false, first = true;
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (set_disk(i, j, players[pl]))
						{
							flag = true;
							if (!first)
								printf(" ");
							first = false;
							printf("(%d,%d)", i + 1, j + 1);
						}
					}
				}
				if (!flag)
					printf("No legal move.");
				printf("\n");
			}// if L
			else
			{
				int disk_r = cmd[1] - '0' - 1, disk_c = cmd[2] - '0' - 1;
				bool flag = set_disk(disk_r, disk_c, players[pl]);
				if (!flag)
					pl = (pl + 1) % 2;
				move_disk(disk_r, disk_c, players[pl]);
				check_disk();
				printf("Black - %2d White - %2d\n", black_num, white_num);
				pl = (pl + 1) % 2;
			}
		}//while scanf
		for (int i = 0; i < 8; i++)
			printf("%s\n", board[i]);
	}//while
	return 0;
}