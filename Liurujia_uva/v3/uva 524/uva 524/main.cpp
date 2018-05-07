#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

int is_prime(int n)
{
	int k = floor(sqrt(n) + 0.5);
	for (int i = 2; i <= k; i++)
	{
		if (0 == n % i)
			return 0;
	}
	return 1;
}

const int maxn = 16 + 10;
bool vis[maxn];
int isp[maxn * 2];
int N;
int ans[maxn];

void init()
{
	isp[0] = 0;isp[1] = 0;
	for (int i = 2; i < maxn * 2; i++)
		isp[i] = is_prime(i);
}


void dfs(int layer)
{
	if (layer == N && isp[ans[N - 1] + ans[0]])
	{
		for (int i = 0; i < N - 1; i++)
			cout << ans[i] << " ";
		cout << ans[N - 1] << endl;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		ans[layer] = i;
		if (!vis[i] && isp[ans[layer - 1] + ans[layer]])
		{
			vis[i] = true;
			dfs(layer + 1);
			vis[i] = false;
		}
	}// for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	int kase = 0;
	while (cin >> N && N)
	{
		if (kase)
			cout << endl;
		cout << "Case " << ++kase << ":" << endl;

		memset(ans, -1, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		ans[0] = 1; vis[1] = true;
		dfs(1);
		
	}
}