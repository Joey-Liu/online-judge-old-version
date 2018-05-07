#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;
const int maxn = 80 + 20;

char str[maxn], p_str[maxn], t_str[maxn];

int work()
{
	int res = 0;
	int len = strlen(str);
	for (int i = 1; i <= len; i++)
	{
		memset(p_str, 0, sizeof(p_str));
		memset(t_str, 0, sizeof(t_str));
		if (0 == len % i)
		{
			int times = len / i;
			strncpy(t_str, str, i);
			for (int j = 0; j < times; j++)
				strcat(p_str, t_str);
		}
		if (0 == strcmp(p_str, str))
		{
			res = i;
			break;
		}
	}//for
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	scanf("%d", &kasenum);
	bool flag = true;
	while (kasenum--)
	{
		scanf("%s", str);
		if (!flag)
			printf("\n");
		else
			flag = false;
		printf("%d\n", work());
	}
	return 0;
}