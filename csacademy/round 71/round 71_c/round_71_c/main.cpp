#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 1e5 + 10;
int N, num[maxn];

int main()
{
	while (1 == scanf("%d", &N))
	{
		int x;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &x);
			1 == x ? num[i] = 1 : num[i] = -1;
		}//for

		for (int i = 1; i <= N; i++)
			num[i] = num[i] + num[i - 1];

		int mini = num[0], maxi = num[0];
		int lb = num[0], ub = num[0];
		int lp, rp;
		for (int i = 1; i <= N; i++)
		{
			int trp = num[i] - mini;
			int tlp = num[i] - maxi;
			if (1 == i)
			{
				lp = tlp;
				rp = trp;
			}
			else
			{
				lp = min(lp, tlp);
				rp = max(rp, trp);
			}

			mini = min(mini, num[i]);
			maxi = max(maxi, num[i]);
		}
		lp = min(lp, mini);
		rp = max(rp, maxi);
		cout << rp - lp  + 1<< endl;
	}//while
	return 0;
}