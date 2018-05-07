#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 2000 + 100;
int N, M, K, res;
char seats[maxn][maxn];

void work_row()
{
	int ind = 0;
	for (int i = 0; i < N; i++)
	{
		int j = 0, seq = 0;
		bool seq_st = false;
		while (j < M)
		{
			if ('.' == seats[i][j] && !seq_st)
			{
				seq = 1;
				seq_st = true;
			}
			else if ('.' == seats[i][j] && seq_st)
				seq++;
			else if ('*' == seats[i][j] && seq_st)
			{
				if (seq >= K)
					res += (seq - K + 1);
				seq_st = false;
				seq = 0;
			} 
			j++;
		}//while j < M
		if (seq_st && seq >= K)
			res += (seq - K + 1);
	}//for int i
}


void work_col()
{
	int ind = 0;
	for (int j = 0; j < M; j++)
	{
		int i = 0, seq = 0;
		bool seq_st = false;
		while (i < N)
		{
			if ('.' == seats[i][j] && !seq_st)
			{
				seq = 1;
				seq_st = true;
			}
			else if ('.' == seats[i][j] && seq_st)
				seq++;
			else if ('*' == seats[i][j] && seq_st)
			{
				if (seq >= K)
					res += (seq - K + 1);
				seq_st = false;
				seq = 0;
			}
			i++;
		}//while j < M
		if (seq_st && seq >= K)
			res += (seq - K + 1);
	}//for int i

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++)
		scanf("%s", seats[i]);
	if (N < K && M >= K)
		work_row();
	else if (N >= K && M < K)
		work_col();
	else if (1 == K)
		work_col();
	else if(N >= K && M >= K)
	{
		work_row();
		work_col();
	}

	printf("%d\n", res);
	return 0;
}