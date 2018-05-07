#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double ans = 0.0, pos = 0.0;
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		ans = 0.0;
		for (int i = 0; i < n; i++)
		{
			pos = (double)i / n * (n + m);
			ans += fabs(pos - floor(pos + 0.5)) / (n + m);
		}
		printf("%.4lf\n", ans * 10000.0);
	}//while
	return 0;
}