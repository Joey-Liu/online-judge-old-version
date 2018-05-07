#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 10000 + 100;

struct Ant
{
	int p;	//从左端 记录的位置
	int d;	//方向 ：-1 ：向左  1：向右 0：正在转向
	int id;	

	Ant(int a, int b, int c)
	{
		p = a;
		d = b;
		id = c;
	}

	Ant()
	{
		p = d = id = 0;
	}
}before[maxn], after[maxn];

int cmp(const void * a, const void *b)
{
	Ant * _a = (Ant *)a;
	Ant * _b = (Ant *)b;
	return _a->p - _b->p;
}


int casenum, kase = 0;
int L, T, n;
int ind[maxn];
char dirName[][10] = { "L", "Turning", "R" };

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &casenum);
	while (kase < casenum)
	{
		scanf("%d%d%d", &L, &T, &n);
		char c;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %c", &before[i].p, &c);
			if (c == 'R')
				before[i].d = 1;
			else
				before[i].d = -1;
			before[i].id = i;

			after[i] = Ant{ before[i].p + T * before[i].d, before[i].d, before[i].id };
		}

		qsort(before, n, sizeof(Ant), cmp);
		for (int i = 0; i < n; i++)
			ind[before[i].id] = i;

		qsort(after, n, sizeof(Ant), cmp);
		for (int i = 1; i < n; i++)		//处理 碰撞时候的方向
		{
			if (after[i].p == after[i - 1].p)
				after[i].d = after[i - 1].d = 0;
		}

		printf("Case #%d:\n", ++kase);
		for (int i = 0; i < n; i++)
		{
			int position = ind[i];	//ind 为输入顺序 在 after（before） 中的位置
			if (after[position].p < 0 || after[position].p > L)
				printf("Fell off\n");
			else
				printf("%d %s\n", after[position].p, dirName[after[position].d + 1]);
		}
		printf("\n");
	}//while kase < casenum
	return 0;
}