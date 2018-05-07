#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 10000 + 2;
struct node
{
	int value;
	vector<int > lis;
};

node wp[maxn];
int dp[maxn];
int casenum;
int N, M, W, length, connect;

int work(int nom)		// compute the minimum cost of nom
{
	int ans = 0;
	if (-1 != dp[nom])
		return dp[nom];

	int fixed = 0;
	for (int i = 0; i < wp[nom].lis.size(); i++)
		fixed += work(wp[nom].lis.at(i));

	int price = wp[nom].value;
	if (0 == wp[nom].lis.size())
		ans = price;
	else
	{
		ans = min(price, fixed + W);
	}

	return dp[nom] = ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &casenum);
	while (casenum--)
	{
		for (int i = 0; i < maxn; i++)
		{
			wp[i].value = 0;
			wp[i].lis.clear();
		}
		memset(dp, -1, sizeof(dp));
		scanf("%d %d %d", &N, &M, &W);

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &wp[i].value);
			scanf("%d", &length);
			for (int j = 0; j < length; j++)
			{
				scanf("%d", &connect);
				wp[i].lis.push_back(connect);
			}
		}

		int choice;
		int res = 0;
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &choice);
			res += work(choice);
		}

		printf("%d\n", res);
	}// whlie casenum--

	return 0;
}