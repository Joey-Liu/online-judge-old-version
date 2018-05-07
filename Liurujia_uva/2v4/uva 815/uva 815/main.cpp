#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int maxn = 35;
int city[maxn * maxn], n, m;
double flood;

int cmp(const void *a, const void *b)
{
	int *_a = (int *)a;
	int *_b = (int *)b;
	return *_a - *_b;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (2 == scanf("%d%d", &n, &m) && n && m)
	{
		for (int i = 0; i < n * m; i++)
			scanf("%d", &city[i]);
		
		scanf("%lf", &flood);
		flood /= 100.0;
		qsort(city, n*m, sizeof(city[0]), cmp);
		double elevation = 0.0;
		int cnt = 1;

		for (int i = 1; i < n * m; i++)
		{
			if (flood > i * (city[i] - city[i - 1]))
			{
				flood -= i * (city[i] - city[i - 1]);
				cnt++;
			}
			else
			{
				elevation = flood * 1.0 / i;
				elevation += city[i - 1];
				break;
			}
		}

		if (0.0 == elevation)
			elevation = flood * 1.0 / n / m + city[n*m - 1];
		printf("Region %d\n", ++kasenum);
		printf("Water level is %.2f meters.\n", elevation);
		printf("%.2f percent of the region is under water.\n\n", 100.0 * cnt / n / m);
	}//while
	return 0;
}