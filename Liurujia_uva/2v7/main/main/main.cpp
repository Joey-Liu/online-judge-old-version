#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int maxn = 20;

int N, num[maxn];
bool vis[maxn];

bool isPrime(int n)
{
	if (1 == n)
		return false;
	
	bool flag = true;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (0 == n % i)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

void dfs(int cur)
{
	if (cur == N && isPrime(num[cur - 1] + num[0]))
	{
		printf("%d", num[0]);
		for (int i = 1; i < N; i++)
			printf(" %d", num[i]);
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (!cur || (!vis[i] && isPrime(i + num[cur - 1])))
			{
				num[cur] = i;
				vis[i] = true;
				dfs(cur + 1);
				vis[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int kasenum = 0;
	while (cin >> N && N)
	{
		if (kasenum)
			cout << "\n";
		memset(num, -1, sizeof(num));
		memset(vis, false, sizeof(vis));
		vis[1] = true;
		num[0] = 1;
		cout << "Case " << ++kasenum << ":\n";
		dfs(1);
	}
}