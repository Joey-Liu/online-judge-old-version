//merge_sort things
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 1000000 + 10;
const int mod = 1000000000 + 7;

int a[maxn],la[maxn],ra[maxn];

int merge(int p, int q, int r)		//p.....q.....r in the array
{
	int res = 0;				//the result
	int n1 = q - p + 1;
	int n2 = r - q;
	
	//int la[maxn], ra[maxn];
	for (int i = 1; i <= n1; i++)			//p-------------q
		la[i] = a[p + i - 1];
	for (int i = 1; i <= n2; i++)			//q + 1------------r
		ra[i] = a[q + i];

	int i = 1, j = 1;
	while (i <= n1 && j <= n2)
	{
		if (la[i] > ra[j])
		{
			res += (n1 - i + 1);
			res %= mod;
			a[p++] = ra[j++];
		}
		else
			a[p++] = la[i++];
	}

	while (i <= n1)
		a[p++] = la[i++];
	while (j <= n2)
		a[p++] = ra[j++];

	return (res % mod);
}



int sort(int p, int r)
{
	int res = 0;
	if (p < r)
	{
		int q = (p + r) / 2;
		
		res = (res + sort(p, q) ) % mod;
		res = (res + sort(q + 1, r) ) % mod;
		res = (res + merge(p, q, r)) % mod;
	}

	return (res % mod);
}



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum,num = 0;
	scanf("%d", &casenum);

	while (casenum--)
	{
		scanf("%d", &num);
		for (int i = 0; i < num; i++)
			scanf("%d", &a[i]);

		printf("%d\n", sort(0, num - 1));
	}
	return 0;
}