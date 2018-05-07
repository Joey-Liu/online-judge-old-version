#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

using namespace std;

const int maxn = 1000000;
char context[maxn], ch;
int lines;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	char wandada[] = "wanshen";

	while (1 == scanf("%d", &lines))
	{
		getchar();
		int chnum = 0, linecnt = 0;
		while (true)
		{
			if (linecnt >= lines)
				break;

			if ((ch = getchar()) == EOF || ch == '\n')
			{
				linecnt++;
				continue;
			}
			context[chnum++] = ch;
		}
		context[chnum] = '\0';

		int cnt = 0;
		int i = 0, j = 0;
		while (i < chnum)
		{
			if (context[i] == wandada[j])
			{
				i++; j++;
			}
			else if (j == 0 && context[i] != wandada[j])
				i++;
			else
				j = 0;

			if (j == 7)
			{
				cnt++; j = 0;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}