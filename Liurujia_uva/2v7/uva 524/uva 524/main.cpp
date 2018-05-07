#include <iostream>
#include <stdio.h>
#include <math.h>
#include <memory.h>

using namespace std;

bool is_prime(int n)
{
	if (1 == n)
		return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (0 == n % i)
			return false;
	}
	return true;
}

bool prime[50];

void init()
{
	prime[0] = false;
	for (int i = 1; i < 50; i++)
		prime[i] = is_prime(i);
}

int N, num[20], vis[20];

void dfs(int cur)
{
	if (cur == N)
	{
		if (prime[num[N - 1] + num[0]])
		{
			printf("%d", num[0]);
			for (int i = 1; i < N; i++)
				printf(" %d", num[i]);
			printf("\n");
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!vis[i] && prime[num[cur - 1] + i])
		{
			vis[i] = true;
			num[cur] = i;
			dfs(cur + 1);
			vis[i] = false;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	int kasenum = 0;
	while (cin >> N)
	{
		if(kasenum)
			cout << "\n";
		memset(num, 0, sizeof(num));
		memset(vis, false, sizeof(vis));
		num[0] = 1;
		vis[1] = true;
		cout << "Case " << ++kasenum << ":\n";
		dfs(1);
	}//while
	return 0;
}