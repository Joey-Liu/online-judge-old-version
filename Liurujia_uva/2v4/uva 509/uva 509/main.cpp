#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;

char disk[10][64 * 100 + 100], parity;
int disk_num, bits_num, block_num, hexx = 0;
bool is_parity[10][64 * 100 + 100];

bool check_disk()
{
	bool flag = true;
	for (int j = 0; j < bits_num * block_num; j++)
	{
		int broken_num = 0, broken_pos = -1, col_sum = 0;
		for (int i = 0; i < disk_num; i++)
		{
			if ('x' == disk[i][j])
			{
				broken_num++;
				broken_pos = i;
			}
			else
				col_sum += (disk[i][j] - '0');
		}//for int i

		int par = col_sum % 2;
		if (broken_num > 1)
		{
			flag = false;
			break;
		}
		else if (!broken_num)
		{
			if (('E' == parity && par)
				|| ('O' == parity && !par))
			{
				flag = false;
				break;
			}
		}
		else
		{
			if ('E' == parity)
				disk[broken_pos][j] = (par == 0 ? '0' : '1');
			else
				disk[broken_pos][j] = (par == 0 ? '1' : '0');
		}
	}//for int j
	return flag;
}

void read_disk()
{
	int ind = 0, kk = 0;
	for (int k = 0; k < block_num; k++)
	{
		for (int i = 0; i < disk_num; i++)
		{
			for (int j = 0; j < bits_num; j++)
			{
				int pos = k * bits_num + j;
				if (is_parity[i][pos])
					continue;
				hexx = (hexx << 1) + disk[i][pos] - '0';
				ind++;
				if (ind && 0 == ind % 4)
				{
					printf("%X", hexx);
					hexx = 0;
				}
			}
		}
	}
	int r = ind % 4;
	if (r)
	{
		hexx = (hexx << (4 - r));
		printf("%X", hexx);
		hexx = 0;
	}
	printf("\n");
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (1 == scanf("%d", &disk_num) && disk_num)
	{
		scanf("%d%d", &bits_num, &block_num);
		getchar();
		scanf("%c", &parity);
		memset(is_parity, false, sizeof(is_parity));
		for (int i = 0; i < disk_num; i++)
		{
			for (int j = 0; j < block_num * bits_num; j++)
			{
				if ((j / bits_num + 1) % disk_num == (i + 1) % disk_num)
					is_parity[i][j] = true;
			}
		}
		for (int i = 0; i < disk_num; i++)
			scanf("%s", disk[i]);
		printf("Disk set %d is ", ++kasenum);
		if (!check_disk())
			printf("invalid.\n");
		else
		{
			printf("valid, contents are: ");
			read_disk();
		}
	}//while
	return 0;
}