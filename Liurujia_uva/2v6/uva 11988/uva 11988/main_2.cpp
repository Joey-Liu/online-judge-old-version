#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;

const int maxn = 1e5 + 20;

int po[maxn];
char str[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%s", str + 1))
	{
		int len = strlen(str + 1);
		memset(po, -1, sizeof(0));

		int cur = 0, last = 0;
		for (int i = 1; i <= len; i++)
		{
			if ('[' == str[i])
				cur = 0;
			else if (']' == str[i])
				cur = last;
			else
			{
				if (last == cur)
					last = i;
				int t = po[cur];
				po[cur] = i;
				po[i] = t;
				cur = i;
			}
		}

		cur = po[0];
		for (; cur != -1; cur = po[cur])
			printf("%c", str[cur]);
		printf("\n");
	}//while
	return 0;
}