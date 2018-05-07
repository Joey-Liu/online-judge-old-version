#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 10;
char ip_addr[maxn][40];
int ip_num, eig_dig[4];

char * bina(int k)
{
	char *res = new char[9];
	res[8] = '\0';
	for (int i = 0; i < 8; i++)
		res[i] = '0';

	int ind = 7;
	while (k > 0)
	{
		res[ind--] = k % 2 + '0';
		k /= 2;
	}
	return res;
}

bool check_same(int ind)
{
	bool flag = true;
	for (int i = 1; i < ip_num; i++)
	{
		if (ip_addr[i][ind] != ip_addr[0][ind])
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &ip_num))
	{
		for (int i = 0; i < ip_num; i++)
		{
			scanf("%d.%d.%d.%d", &eig_dig[0], &eig_dig[1], &eig_dig[2], &eig_dig[3]);
			for (int j = 0; j < 4; j++)
			{
				char *r = bina(eig_dig[j]);
				for (int k = 0; k < 8; k++)
					ip_addr[i][k + j * 8] = r[k];
			}
		}

		int ind = 0;
		while (ind < 32)
		{
			if (!check_same(ind))
				break;
			ind++;
		}

		for (int i = 32; i >= ind; i--)
			ip_addr[0][i] = '0';

		for (int i = 0; i < 4; i++)
		{
			int pos = i * 8;
			int res = 0, ind = 0;
			while (ind < 8)
			{
				res = (res << 1) + ip_addr[0][pos] - '0';
				pos++; ind++;
			}
			printf("%d", res);
			if (3 != i)
				printf(".");
		}
		printf("\n");

		int mask[32] = { 0 }, ma = 0;
		for (int i = 0; i < ind; i++)
			mask[i] = 1;

		for (int i = 0; i < 32; i++)
		{
			if (0 == i % 8 && 0 != i)
			{
				printf("%d.", ma);
				ma = 0;
			}
			ma = (ma << 1);
			if (mask[i])
				ma += 1;
		}
		printf("%d\n", ma);
	}
	return 0;
}