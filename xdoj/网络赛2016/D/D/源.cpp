#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int x, y, a;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &x))
	{
		scanf("%d%d", &y, &a);
		int tmp = x + y;
		a = a % tmp;
		
		if (a == 0)
		{
			printf("light\n");
			continue;
		}
		a -= x;
		if (a <= 0)
		{
			printf("wanshen\n");
			continue;
		}
		a -= y;
		if (a <= 0)
		{
			printf("light\n");
			continue;
		}
	}
	return 0;
}