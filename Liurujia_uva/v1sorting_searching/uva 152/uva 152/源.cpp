#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;
struct Tree
{
	double x, y, z;
};

const int maxn = 5000 + 500;
int treeNum = 0;
Tree trees[maxn];
int hiso[15] = { 0 };

int cmp(const void * a, const void * b)
{
	Tree * m = (Tree *)a;
	Tree * n = (Tree *)b;

	if (m->x != n->x)
		return m->x > n->x ? 1 : -1;
	if (m->y != n->y)
		return  m->y > n->y ? 1 : -1;
	if (m->z != n->z)
		return  m->z > n->z ? 1 : -1;
	return 0;
}

double dist(int a, int b)
{
	double res = pow(trees[a].x - trees[b].x, 2);
	res += pow(trees[a].y - trees[b].y, 2);
	res += pow(trees[a].z - trees[b].z, 2);
	return sqrt(res);
}

int search(int xx)
{
	double midist = 1e10, temp;
	for (int i = 0; i < treeNum; i++)
	{
		if (i == xx)
			continue;
		temp = dist(i, xx);
		if (temp < midist)
			midist = temp;
	}
	return (int)midist;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double ta = 0, tb = 0, tc = 0;
	while (3 == scanf("%lf%lf%lf", &ta, &tb, &tc))
	{
		if (0 == ta && 0 == tb && 0 == tc)
			break;
		trees[treeNum].x = ta;
		trees[treeNum].y = tb;
		trees[treeNum].z = tc;
		treeNum++;
	}//while

	int disl = 0x7fffffff, disr = 0x7fffffff, mdis = 0;
	
	for (int i = 0; i < treeNum; i++)
	{
		int res = search(i);
		if (res > 10)
			continue;
		hiso[res]++;
	}//for int i
	for (int i = 0; i < 10; i++)
		printf("%4d", hiso[i]);
	printf("\n");

	return 0;
}
