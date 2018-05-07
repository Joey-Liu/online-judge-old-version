#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int gcd(int a, int b)
{
	if (0 == b)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int st, mo;
	while (2 == scanf("%d%d", &st, &mo))
	{
		printf("%10d%10d", st, mo);
		printf("    ");
		if (1 == gcd(st, mo))
			printf("Good Choice\n\n");
		else
			printf("Bad Choice\n\n");
	}
	return 0;
}