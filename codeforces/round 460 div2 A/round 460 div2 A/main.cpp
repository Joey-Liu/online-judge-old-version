#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, M, a, b;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d%d", &N, &M);
	bool flag = true;
	int ta, tb;
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &a, &b);
		if (flag)
		{
			ta = a;
			tb = b;
		}
		flag = false;

		int x = a * tb;
		int y = ta * b;
		if (x < y)
		{
			ta = a;
			tb = b;
		}
	}
	double res = 1.0 * ta / tb * M;
	printf("%.8f\n", res);
	return 0;
}