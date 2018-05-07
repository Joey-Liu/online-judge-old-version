#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 1000 + 50;
char seq[50 + 10][maxn];
char res_seq[maxn];
int seq_num, seq_len, hammDis;

int char2int(char c)
{
	if ('A' == c)
		return 0;
	else if ('C' == c)
		return 1;
	else if ('G' == c)
		return 2;
	else
		return 3;
}

char getCans(int j)
{
	int Cnum[4] = { 0 };
	for (int i = 0; i < seq_num; i++)
		Cnum[char2int(seq[i][j])]++;
	int tmpMax = Cnum[0], ind = 0, cErr = 0;
	for (int i = 0; i < 4; i++)
	{
		if (tmpMax < Cnum[i])
		{
			tmpMax = Cnum[i];
			ind = i;
		}
	}
	hammDis += (seq_num - tmpMax);
	if (0 == ind)
		return 'A';
	else if (1 == ind)
		return 'C';
	else if (2 == ind)
		return 'G';
	else
		return 'T';
}

void work()
{
	hammDis = 0;
	for (int j = 0; j < seq_len; j++)
		res_seq[j] = getCans(j);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		scanf("%d%d", &seq_num, &seq_len);
		for (int i = 0; i < seq_num; i++)
			scanf("%s", seq[i]);

		memset(res_seq, 0, sizeof(res_seq));
		work();
		printf("%s\n", res_seq);
		printf("%d\n", hammDis);
	}//while
	return 0;
}