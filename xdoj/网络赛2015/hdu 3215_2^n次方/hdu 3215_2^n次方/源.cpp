#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int maxn = 10000 + 100;
int a[maxn];			//a[i]记录 2^i次方 的最高位
const double lg2 = log10(2);

void  init()
{
	a[0] = 1;
	a[1] = 2;
	a[2] = 4;
	a[3] = 8;

	for (int i = 0; i < maxn; i++)
	{
		double fractpart = i * lg2 - int(i * lg2 + 1e-7);
		a[i] = (int)(pow(double(10), fractpart) + 1e-7);
	}
}

int main()
{
	init();
	int N; int sta[10];
	while (cin >> N && N!= -1)
	{
		memset(sta, 0, sizeof(sta));
		for (int i = 0; i <= N; i++)
			sta[a[i]]++;

		printf("%d", sta[1]);
		for (int i = 2; i < 10; i++)
			printf(" %d", sta[i]);
		printf("\n");
	}
	return 0;
}