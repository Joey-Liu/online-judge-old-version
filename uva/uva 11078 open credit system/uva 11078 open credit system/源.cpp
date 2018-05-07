#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>


using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kase, a, b, n, ans;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d", &n);
		scanf("%d%d", &a, &b);
		n -= 2;
		ans = a - b;

		a = max(a, b);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &b);
			ans = max(ans, a - b);
			a = max(a, b);
		}
		printf("%d\n", ans);
	}

	return 0;
}