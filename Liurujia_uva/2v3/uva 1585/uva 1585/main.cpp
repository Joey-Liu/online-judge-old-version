#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 80 + 20;
char str[maxn];
int kasenum;

int work()
{
	int score = 0, bonus = 1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == 'O')
		{
			score += bonus;
			bonus++;
		}
		else
			bonus = 1;
	}
	return score;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		scanf("%s", str);
		int score = work();
		printf("%d\n", score);
	}//while
	return 0;
}