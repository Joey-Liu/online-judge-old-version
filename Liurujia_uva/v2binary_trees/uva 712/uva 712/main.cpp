#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
const int maxn = 1024 + 512;
int depth, kasenum, testnum = 0;
char str[maxn], ch, ans[maxn]; 
int values[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &depth) && depth)
	{
		memset(ans, 0, sizeof(ans));
		getchar();
		gets(str);
		for (int i = 0; i < pow(2, depth); i++)
		{
			ch = getchar();
			values[i] = ch - '0';
		}
		getchar();

		scanf("%d", &kasenum);
		getchar();
		for (int i = 0; i < kasenum; i++)
		{
			int index = 0, exp = 0;
			gets(str);
			for (int j = depth - 1; j >= 0; j--)
			{
				if ('1' == str[j])
					index += (int)pow(2, exp);
				exp++;
			}
			ans[i] = '0' + values[index];
		}//fot int i
		printf("S-Tree #%d:\n", ++testnum);
		printf("%s\n\n", ans);
	}//while
	return 0;
}