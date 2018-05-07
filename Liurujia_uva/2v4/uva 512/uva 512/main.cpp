#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 50 + 50;
const int BIG = 1000;
int sheet[maxn][maxn], tmp_sheet[maxn][maxn], ans[maxn][maxn];
int row, col, cmd_num, seq_num, seqs[maxn], query_num, r1, c1, r2, c2, qr, qc;
char cmd[10];

void init()
{
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			sheet[i][j] = BIG * i + j;
}

void mycopy(char type, int p, int q)
{
	if ('R' == type)
	{
		for (int i = 0; i <= col; i++)
			sheet[p][i] = tmp_sheet[q][i];
	}
	else
	{
		for (int i = 0; i <= row; i++)
			sheet[i][p] = tmp_sheet[i][q];
	}
}

void insert(char type)
{
	memcpy(tmp_sheet, sheet, sizeof(sheet));
	int ind = 1, cnt = 0;
	cnt = ('R' == type ? row: col);
	int t_max;
	for (int i = 1; i < maxn; i++)
		if (seqs[i])
			t_max = i;

	for (int i = 1; i <= cnt; i++)
	{
		if (seqs[i])
			mycopy(type, ind++, 0);
		mycopy(type, ind++, i);
	}

	if (t_max == cnt + 1)
		mycopy(type, ind++, 0);
	ind--;
	if ('R' == type)
		row = ind;
	else
		col = ind;
}


void del(char type)
{
	memcpy(tmp_sheet, sheet, sizeof(sheet));
	int ind = 1, cnt = 0;
	int t_max;
	for (int i = 1; i < maxn; i++)
		if (seqs[i])
			t_max = i;

	cnt = ('R' == type ? row : col);
	for (int i = 1; i <= cnt; i++)
	{
		if (seqs[i])
			continue;
		mycopy(type, ind++, i);
	}//for int i
	ind--;
	if ('R' == type)
		row = ind;
	else
		col = ind;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	bool flag = true;
	while (2 == scanf("%d%d", &row, &col) && row)
	{
		if (!flag)
			printf("\n");
		flag = false;
		memset(sheet, 0, sizeof(sheet));
		memset(tmp_sheet, 0, sizeof(tmp_sheet));
		memset(ans, 0, sizeof(ans));
		init();
		scanf("%d", &cmd_num);
		for (int i = 0; i < cmd_num; i++)
		{
			scanf("%s", cmd);
			if ('E' == cmd[0])
			{
				scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
				swap(sheet[r1][c1], sheet[r2][c2]);
			}
			else
			{
				memset(seqs, 0, sizeof(seqs));
				scanf("%d", &seq_num);
				for (int i = 0; i < seq_num; i++)
				{
					int ind;
					scanf("%d", &ind);
					seqs[ind] = 1;
				}
				if ('I' == cmd[0])
					insert(cmd[1]);
				else
					del(cmd[1]);
			}
		}//for int i
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				ans[sheet[i][j] / BIG][sheet[i][j] % BIG] = i * BIG + j;

		printf("Spreadsheet #%d\n", ++kasenum);
		scanf("%d", &query_num);
		for (int i = 0; i < query_num; i++)
		{
			scanf("%d%d", &qr, &qc);
			if (!ans[qr][qc])
				printf("Cell data in (%d,%d) GONE\n", qr, qc);
			else
			{
				int index = ans[qr][qc];
				printf("Cell data in (%d,%d) moved to (%d,%d)\n", qr, qc, index / BIG, index % BIG);
			}
		}
	}//while
	return 0;
}