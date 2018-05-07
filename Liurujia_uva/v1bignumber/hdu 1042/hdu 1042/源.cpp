#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <memory.h>

using namespace std;
const int maxn = 9000;

int num[maxn], N;

void work()
{
	int c = 0;
	num[0] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			int res = num[j] * i + c;
			num[j] = res % 10000;
			c = res / 10000;
		}
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &N))
	{
		if (!N)
			printf("1\n");
		else
		{
			memset(num, 0, sizeof(num));
			work();
			int index;
			for (index = maxn - 1; index >= 0; index--)
			{
				if (num[index])
					break;
			}
			printf("%d", num[index]);
			for (int i = index - 1; i >= 0; i--)
				printf("%04d", num[i]);
			printf("\n");
		}
	}
	return 0;
}