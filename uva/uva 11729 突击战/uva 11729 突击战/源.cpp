#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 1000 + 100;

int N;
struct job 
{
	int jt;
	int bt;
};
job jo[maxn];

int cmp(const void *a, const void *b)
{
	job* _a = (job *)a;
	job* _b = (job *)b;

	return _b->jt - _a->jt;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int res = 0, cur = 0, casenum = 1;
	while (1 == scanf("%d", &N))
	{
		if (0 == N)
			break;
		
		memset(jo, 0, sizeof(jo));
		res = -1, cur = 0;
		for (int i = 0; i < N; i++)
			scanf("%d%d", &jo[i].bt, &jo[i].jt);
		qsort(jo, N, sizeof(job), cmp);

		for (int i = 0; i < N; i++)
		{
			cur += jo[i].bt;
			if (res < cur + jo[i].jt)
				res = cur + jo[i].jt;
		}
		printf("Case %d: %d\n", casenum++, res);
	}
	return 0;
}