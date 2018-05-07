#include <iostream>
#include <stdio.h>
#include <math.h>
#include <memory.h>

using namespace std;

int N;
bool visited[10];

bool check(int x, int y)
{
	if (x < 10000)
		visited[0]++;
	if (y < 10000)
		visited[0]++;

	if (y > 99999)
		return false;

	while (x > 0)
	{
		visited[x % 10]++;
		x /= 10;
	}
	while (y > 0)
	{
		visited[y % 10]++;
		y /= 10;
	}

	for (int i = 0; i < 10; i++)
		if (visited[i] != 1)
			return false;

	return true;
}

int main()
{
	bool first = true;
	while (1 == scanf("%d", &N) && N)
	{
		if (!first)
			printf("\n");
		bool has_solo = false;
		for (int i = 1000; i <= 99999; i++)
		{
			memset(visited, 0, sizeof(visited));
			int a = i;
			int b = a * N;
			bool flag = check(a, b);
			if (flag)
			{
				has_solo = true;
				printf("%05d / %05d = %d\n", b, a, N);
			}
		}
		if (!has_solo)
			printf("There are no solutions for %d.\n", N);
		first = false;
	}
	return 0;
}