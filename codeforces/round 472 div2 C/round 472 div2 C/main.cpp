#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 500;

int N, U;
double E[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	scanf("%d%d", &N, &U);
	//cin >> N >> U;
	for (int i = 0; i < N; i++)
		scanf("%lf", &E[i]);

	bool flag = false;
	double res = -1;

	for (int i = 0; i < N - 1; i++)
	{
		double ut = E[i] + U;
		int ind = lower_bound(E, E + N, ut) - E;
		if (ind == N)
			ind--;

		while (E[ind] > ut)
			ind--;
		
		if (ind - i <= 1)
			continue;
		
		flag = true;
		double t = (E[ind] - E[i + 1]) / (E[ind] - E[i]);
		res = max(t, res);
	}
	
	if (!flag)
		printf("-1\n");
	else
		printf("%.9f\n", res);
	
	return 0;
}