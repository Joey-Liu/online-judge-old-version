#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 200 + 100;
char ori_names[maxn][150];
char res_names[maxn][150];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum = 0, turtlenum = 0;
	scanf("%d", &kasenum);

	while (kasenum--)
	{
		scanf("%d", &turtlenum);
		getchar();
		for (int i = 0; i < turtlenum; i++)
			gets(ori_names[i]);
		for (int i = 0; i < turtlenum; i++)
			gets(res_names[i]);

		int p = turtlenum - 1, q = turtlenum - 1;
		while (p >= 0)
		{
			if (!strcmp(ori_names[p], res_names[q]))
				q--;
			p--;
		}

		while (q >= 0)
			printf("%s\n", res_names[q--]);
		printf("\n");
	}//while
	return 0;
}