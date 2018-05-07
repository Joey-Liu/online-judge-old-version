#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;
const int maxn = 300 + 10;

int T, N, requestNum, req[maxn][3];
int sseq[maxn][3];
int res = 0;

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int*)b;
}

const int sstmp[6][3] = { { 0, 1, 2 },{ 0, 2, 1 },
{ 1, 0, 2 },{ 1, 2 ,0 },{ 2, 1, 0 },{ 2, 0, 1 } };

void work()
{
	int rsum = 0, candy = N, flag = false;;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (candy >= req[i][sseq[i][j]])
			{
				candy -= req[i][sseq[i][j]];
				rsum += 1;
			}
		}
	}
	if (rsum > res)
		res = rsum;
}


void genSeq(int layer)
{
	if (layer >= T)
		work();
	else
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				sseq[layer][j] = sstmp[i][j];
			}
			genSeq(layer + 1);
		}
	}
}

int main()
{
	freopen("in2.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> T;
	requestNum = T * 3;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> req[i][j];
	}

	genSeq(0);
	cout << res;
	return 0;
}