#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;

int num[maxn];
int dp[maxn];	//dp[i] ���������Ϊ i ʱ�����ֵ,��Ŵ�1��ʼ
int N;

void work()
{
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < i; j++)				//����ط� j��0��ʼ��ʹ�õ���j��СҲ��num[i]
		{
			if (num[j] < num[i])
				dp[i] = max(dp[i], dp[j] + num[i]);
		}
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &N) && N > 0)
	{
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));

		for (int i = 1; i <= N; i++)
			scanf("%d", &num[i]);
		dp[1] = num[1];
		int ans = -1;
		work();

		for (int i = 1; i <= N; i++)
		{
			if (ans < dp[i])
				ans = dp[i];
		}

		printf("%d\n", ans);
	}
	return 0;
}