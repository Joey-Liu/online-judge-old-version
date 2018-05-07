#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 10 + 10;
int kasenum, s;
double r;
int idx = 0;
int weight[maxn];
bool usable[maxn];
double lw[maxn], rw[maxn], ans;
bool flag = false;

void DFS(int layer)
{
	if (layer == s)
		return;
	for (int i = 0; i < maxn; i++)
	{
		if (!usable[i])
			continue;
		for (int j = 0; j < maxn; j++)
		{
			if (j == i || !usable[j])
				continue;
			double Ld = max(lw[i], lw[j] - 1);
			double Rd = max(rw[i] - 1, rw[j]);

			if (Ld + Rd + 1 < r)
			{
				if (layer == s - 1)
					ans = max(ans, Ld + Rd + 1);
				usable[i] = usable[j] = false;
				weight[idx] = weight[i] + weight[j];
				usable[idx] = true;
				lw[idx] = weight[j] * 1.0 / weight[idx] + Ld;
				rw[idx] = weight[i] * 1.0 / weight[idx] + Rd;

				idx += 1;
				DFS(layer + 1);

				idx -= 1;
				usable[i] = usable[j] = true;
				usable[idx] = false;
			}// if
		}//for int j
	}// for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		scanf("%lf%d", &r, &s);
		memset(weight, 0, sizeof(weight));
		memset(usable, false, sizeof(usable));
		for (int i = 0; i < maxn; i++)
		{
			lw[i] = 0.0;
			rw[i] = 0.0;
		}

		ans = -1;
		for (idx = 0; idx < s; idx++)
		{
			scanf("%d", &weight[idx]);
			usable[idx] = true;
		}

		if (s == 1) 
		{
			printf("0.0000000000\n"); 
			continue;
		}
		
		flag = false;
		DFS(1);
		printf("%.10lf\n", ans);
	}//while kasenum,
	return 0;
}
