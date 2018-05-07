#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

const int maxn = 80 * 3;
int pile[maxn], ind;
vector<int> vi;

void work(int pos)
{
	int val;
	cin >> val;
	if (-1 == val)
		return;
	
	pile[pos] += val;
	work(pos - 1);
	work(pos + 1);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string str;
	int kasenum = 0;
	while (true)
	{
		if (kasenum)
			printf("\n");
		memset(pile, 0, sizeof(pile));
		int val;
		cin >> val;
		if (-1 == val)
			break;

		pile[maxn / 2] = val;
		work(maxn / 2 - 1);
		work(maxn / 2 + 1);

		int st = maxn / 2;
		while (pile[st])
			st--;
		st++;
		printf("Case %d:\n", ++kasenum);
		printf("%d", pile[st]);
		for (st++; pile[st]; st++)
			printf(" %d", pile[st]);
		printf("\n");
	}
	return 0;
}