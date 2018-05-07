#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 10 + 5;
int top[maxn];
int num, k;

//min heap
void heapify(int pos)
{
	int minm = pos;
	int lp = pos * 2;
	int rp = lp + 1;

	if (lp <= k && top[lp] < top[minm])
		minm = lp;
	if (rp <= k && top[rp] < top[minm])
		minm = rp;

	if (minm != pos)
	{
		swap(top[pos], top[minm]);
		heapify(minm);
	}
}

void heap_sort()
{
	int index = 1;
	for (int i = k; i > 0; i--)
	{
		swap(top[k--], top[1]);
		heapify(1);
	}
}


void build_heap()
{
	for (int i = k / 2; i > 0; i--)
		heapify(i);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (scanf("%d%d",&num,&k) == 2)
	{
		memset(top, 0, sizeof(top));
		if (0 == num && k == 0)
			break;

		k = k < num ? k : num;
		int tk = k;
		for (int i = 1; i <= k; i++)
			scanf("%d", &top[i]);
		build_heap();


		for (int i = 1; i <= num - k; i++)
		{
			scanf("%d", &top[0]);
			if (top[0] > top[1])
			{
				top[1] = top[0];
				heapify(1);
			}
		}

		heap_sort();
		for (int i = 1; i < tk; i++)
			printf("%d ", top[i]);
		printf("%d\n", top[tk]);
	}//while

	return 0;
}