#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>

using namespace std;
const int maxn = 0x7fffffff;
char first[1000], second[1000];
double a, b;
char ch;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (3 == scanf("%s %c %s", first, &ch, second))
	{
		sscanf(first, "%lf", &a);
		sscanf(second, "%lf", &b);

		printf("%s %c %s\n", first, ch, second);
		if (a > maxn)
			printf("first number too big\n");
		if (b > maxn)
			printf("second number too big\n");
		if ((ch == '+') && (a + b > maxn))
			printf("result too big\n");
		if ((ch == '*' && (a * b) > maxn))
			printf("result too big\n");
	}
}