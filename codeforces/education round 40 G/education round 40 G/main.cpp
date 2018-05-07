#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 500000 + 50;

LL N, R, K, a[maxn], dp[maxn];

bool check(LL level, LL rev)
{
	memset(dp, 0, sizeof(dp));
	for (LL i = 1; i <= N; i++)
	{
		LL lp = max(i - R, LL(1));
		LL rp = min(i + R + 1, N + 1);
		dp[lp] += a[i];
		dp[rp] -= a[i];
	}

	for (LL i = 1; i <= N; i++)
	{
		dp[i] += dp[i - 1];
		if (dp[i] < level)
		{
			LL chi = level - dp[i];
			if (rev >= chi)
			{
				LL rind = min(N + 1, i + 2 * R + 1);
				dp[rind] -= chi;
				dp[i] += chi;
				rev -= chi;
			}
			else
				return false;
		}
	}
	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> R >> K;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	
	LL lp = 0, rp = 3e18, mid;
	while (lp < rp)
	{
		mid = (lp + rp) >> 1;
		if (check(mid, K))
			lp = mid + 1;
		else
			rp = mid - 1;
	}
	if (check(lp, K))
		cout << lp << endl;
	else
		cout << lp - 1 << endl;
	return 0;
}