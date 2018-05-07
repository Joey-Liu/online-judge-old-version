#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 100 + 30;
int rnd, wr_cnt, left_cnt;
char answ[maxn], guss[maxn];
bool visited[30];

int work()
{
	wr_cnt = 0;
	left_cnt = strlen(answ);
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < strlen(guss); i++)
	{
		if (!visited[guss[i] - 'a'])
			visited[guss[i] - 'a'] = true;
		else
			continue;

		bool flag = false;
		for (int j = 0; j < strlen(answ); j++)
		{
			if (guss[i] == answ[j])
			{
				left_cnt--;
				answ[j] = ' ';
				flag = true;
			}
		}
		if (!flag)
			wr_cnt++;
		if (wr_cnt >= 7)
			break;
	}//for int i
	if (!left_cnt)
		return 0;
	else if (wr_cnt >= 7)
		return 2;
	else
		return 1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	const char *res[] = { "You win.", "You chickened out.", "You lose." };
	int kasenum = 0;
	while (scanf("%d", &rnd))
	{
		if (rnd < 0)
			break;
		scanf("%s%s", answ, guss);
		int ind = work();
		printf("Round %d\n", ++kasenum);
		printf("%s\n", res[ind]);
	}//while
	return 0;
}