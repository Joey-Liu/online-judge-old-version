//#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//const int maxn = 100 + 10;
//
//int num[maxn], dp[maxn][maxn];
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	int m, n;
//	while (cin >> m >> n)
//	{
//		memset(dp, 0, sizeof(dp));
//		for (int i = 1; i <= n; i++)
//			cin >> num[i];
//		
//		//��ʼ�� dp�߽� ������Ӵ���dp
//		for (int i = 1; i <= n; i++)
//			dp[1][i] = num[i];
//		for (int i = 2; i <= n; i++)
//			dp[1][i] = max(dp[1][i - 1] + num[i], num[i]);
//		
//		//dp���� dp[i][j] = max(dp[i][j - 1] + num[j], dp[i - 1][t] + num[j]) i - 1 <= t <= j - 1
//		int tmax = -0x7fffffff;
//		for (int i = 2; i <= m; i++)		//�� 2 �ο�ʼ
//		{
//			for (int j = i; j <= n; j++)
//			{
//				for (int t = i - 1; t <= j - 1; t++)
//				{
//					if (tmax < dp[i - 1][t] + num[j])
//						tmax = dp[i - 1][t] + num[j];
//				}
//				if (j > i && tmax < dp[i][j - 1] + num[j])	//�� j-1 < i ʱ(��һ��ѭ�� j = i)�������ٴ��ж�,��Ϊ������ѭ�����Ѿ��жϹ���
//					tmax = dp[i][j - 1] + num[j];
//				dp[i][j] = tmax;
//				tmax = -0x7fffffff;
//			}// for int j
//		}// for int i
//		cout << dp[m][n] << endl;
//	}//while
//
//	return 0;
//}


//��Ҫ˼�� dp[][] ���� ����ĿҪ������ ���������ģ�
// dp[i][j] = max(dp[i][ j - 1],dp[i - 1][t]) + num[j]  i - 1 <= t <= j - 1
//�뷨�� ����ÿ����dp[i][j] ʱ ���ǿ��Եõ�dp[i][t] i<= t <= j�����ֵ(����dp[i][j])
//�����ֵ ����һ�ּ��� dp[i + 1][j + 1] ��ʱ���ʹ�õ�
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 100000 + 5;
int num[maxn], pre_max[maxn];

int dp(int n,int m)
{
	int tmp = 0;
	for (int i = 1; i <= m; i++)
	{
		int tmp = 0;
		for (int k = 1; k <= i; k++)
			tmp += num[k];
		pre_max[n] = tmp;

		for (int j = i + 1; j <= n; j++)
		{
			tmp = max(pre_max[j - 1], tmp) + num[j];
			pre_max[j - 1] = pre_max[n];
			pre_max[n] = max(pre_max[n], tmp);
		}
	}//for int i
	return pre_max[n];
}


int main()
{
	int n, m;
	while (cin >> m >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
			pre_max[i] = 0;
		}
		cout << dp(n, m) << endl;
	}
	return 0;
}

