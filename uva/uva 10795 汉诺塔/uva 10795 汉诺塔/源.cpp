#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
const int maxn = 60 + 10;
int start[maxn], finish[maxn];

//汉诺塔状态为p, 把1-i的圆盘移动到 final上
long long func(int* p, int i, int final)
{
	if (0 == i)
		return 0;
	if (p[i] == final)
		return func(p, i - 1, final);
	return func(p, i - 1, 6 - final - p[i]) + (1LL << (i - 1));
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum = 0, disks = 0;
	scanf("%d", &disks);
	while (disks)
	{
		for (int i = 1; i <= disks; i++)
			scanf("%d", &start[i]);
		for (int i = 1; i <= disks; i++)
			scanf("%d", &finish[i]);

		long long res = 0;
		int k = disks;
		while (k >= 1 && finish[k] == start[k])	//求出最大需要移动圆盘的序号
			k--;
		
		if (k < 1)
			res = 0;
		else
		{
			res = func(start, k - 1, 6 - start[k] - finish[k]) +
				func(finish, k - 1, 6 - start[k] - finish[k]) + 1;
		}
		printf("Case %d: %lld\n", ++casenum, res);
		scanf("%d", &disks);
	}//while

	return 0;
}