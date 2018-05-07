#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 100000 + 20;
char a[maxn], b[maxn], ch;
int exist[30];
int chcnt = 0, tmp = 0;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while ((a[0] = getchar()) != EOF)
	{
		int alen = 1;
		while ((ch = getchar()) && ch != ' ')
			a[alen++] = ch;
		
		memset(exist, 0, sizeof(exist));
		while (((ch = getchar()) != EOF) && ch != '\n')
			exist[ch - 'a' + 1] = 1;

		bool outflag = false;
		for (int i = 0; i < alen; i++)
		{
			if (exist[a[i] - 'a' + 1] == 0)
			{
				printf("%c", a[i]);
				outflag = true;
			}
		}
		if (!outflag)
			printf("EMPTY");
		printf("\n");
	}//while scanf

	return 0;
}