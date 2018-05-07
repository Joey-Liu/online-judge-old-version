#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>

using namespace std;
const int maxn = 1000 + 20;
int n, k;
long long tmp, res;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (EOF != scanf("%d%d", &n, &k))
	{
		while (!pq.empty())
			pq.pop();
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &tmp);
			pq.push(tmp);
		}

		res = 0;
		while (!pq.empty())
		{
			tmp = 0; 
			if (pq.size() > k)
			{
				for (int i = 0; i < k; i++)
				{
					tmp += pq.top();
					pq.pop();
				}
			}
			else
			{
				while (!pq.empty())
				{
					tmp += pq.top();
					pq.pop();
				}
			}

			res += tmp;
			if (pq.empty())
				break;
			else if (k != 1)
				pq.push(tmp);
		}
		printf("%lld\n", res);
	}//while

	return 0;
}