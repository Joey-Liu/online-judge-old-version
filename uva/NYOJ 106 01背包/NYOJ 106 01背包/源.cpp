#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef struct
{
	int perValue;
	int weight;
}STUFF;

const int maxn = 2000;
int m, s;
STUFF stuff[maxn];

int cmp(const void * a, const void * b)
{
	STUFF *_a = (STUFF*)a;
	STUFF *_b = (STUFF*)b;
	return _a->perValue - _b->perValue;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	cin >> casenum;
	while (casenum--)
	{
		cin >> s >> m;
		for (int i = 0; i < s; i++)
			cin >> stuff[i].perValue >> stuff[i].weight;
		qsort(stuff, s, sizeof(stuff[0]), cmp);
		int res = 0, index = s - 1;

		while (m > 0 && index >= 0)
		{
			if (m >= stuff[index].weight)
			{
				res += stuff[index].weight * stuff[index].perValue;
				m -= stuff[index].weight;
				index--;
			}
			else
			{
				res += stuff[index].perValue;
				m--;
				stuff[index].weight--;
				if (stuff[index].weight <= 0)
					index--;
			}
		}
		cout << res << endl;
	}

	return 0;
}