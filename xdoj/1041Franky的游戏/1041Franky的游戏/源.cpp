#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int n, m, casenum;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &casenum);
	
	while (casenum--)
	{
		scanf("%d %d", &n, &m);
		if (1 == n % 2 || 1 == m % 2)
			printf("1\n");
		else
			printf("2\n");
	}
}