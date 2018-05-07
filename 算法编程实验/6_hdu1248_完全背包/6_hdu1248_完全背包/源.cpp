#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 10000 + 100;
int f[maxn];
const int wc[] = { 150, 200, 350 };
int casenum, money;

void work()
{
	for (int i = 0; i < 3; i++)
	{
		for (int v = wc[i]; v <= money; v++)
		{
			f[v] = max(f[v], f[v - wc[i]] + wc[i]);
		}
	}//for int i
}

int main()
{
	cin >> casenum;
	while (casenum--)
	{
		memset(f, 0, sizeof(f));
		cin >> money;
		work();
		cout << money - f[money] << endl;
	}
	return 0;
}