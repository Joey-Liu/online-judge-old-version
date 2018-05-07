#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 80 + 20;
char seq[maxn];

int N, L, cnt = 0;

int dfs(int cur)
{
	strtok()
	if (cnt == N)
	{
		int len = cur;
		for (int i = 0; i < len; i++)
		{
			printf("%c", seq[i]);
			if (3 == i % 4 && i != len - 1 && 63 != i % 64)
				printf(" ");
			if (63 == i % 64 && i != len - 1)
				printf("\n");
		}
		printf("\n%d\n", len);
		return 0;
	}
	

	for (int i = 0; i < L; i++)
	{
		seq[cur] = i + 'A';
		bool ok = true;
		for (int j = 1; 2 * j <= cur + 1; j++)
		{
			bool equal = true;
			for (int k = 0; k < j; k++)
			{
				if (seq[cur - k] != seq[cur - k - j])
				{
					equal = false;
					break;
				}
			}//for int k
			if (equal)
			{
				ok = false;
				break;
			}
		}//for int j
		if (ok)
		{
			cnt += 1;
			int r =	dfs(cur + 1);
			if (0 == r)
				return 0;
		}
	}//for int i
	return 1;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (cin >> N >> L)
	{
		if (!N && !L)
			break;
		cnt = 0;
		memset(seq, 0, sizeof(seq));
		dfs(0);
	}//while
	return 0;
}