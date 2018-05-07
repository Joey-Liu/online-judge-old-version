#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 20 + 10;

int N, k, m, rest, visited[maxn];

int go(int p1, int direct, int step)
{
	int pos = p1;
	while (step--)
	{
		pos = (pos + direct + N) % N;
		while (visited[pos])
			pos = (pos + direct + N) % N;
	}//while
	return pos;
}

int main()
{
	while (cin >> N >> k >> m)
	{
		if (!N || !k || !m)
			break;
		rest = N;
		int pos1 = N- 1, pos2 = 0;
		memset(visited, false, sizeof(visited));
		bool first = true;
		while (rest)
		{
			if (!first)
				printf(",");
			first = false;
			pos1 = go(pos1, 1, k);
			pos2 = go(pos2, -1, m);
			visited[pos1] = true;
			rest--;
			printf("%3d", pos1 + 1);
			if (pos1 != pos2)
			{
				visited[pos2] = true;
				rest--;
				printf("%3d", pos2 + 1);
			}
		}//while rest
		printf("\n");
	}//while
	return 0;
}