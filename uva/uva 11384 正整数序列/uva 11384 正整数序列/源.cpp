#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int fun(int n)
{
	return 1 == n ? 1 : 1 + fun(n / 2);
}

int main()
{
	int n;
	while (1 == scanf("%d", &n))
		printf("%d\n", fun(n));

	return 0;
}