//�����㷨
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 100000 + 10;
const int mini = -100000000;

int num[maxn];
//int memo[maxn][maxn];

int find_cross_subarray(int low,int high,int  & cross_low,int & cross_high)// low_max Ϊ���е� ��������ߵ��±꣬high_max Ϊ���е� �������ұߵ��±�
{
	int mid = (low + high) / 2;
	int res = 0;
	
	int left_sum = mini;
	for (int i = mid; i >= low; i--)
	{
		res += num[i];
		if (res >= left_sum)		//�����һ�� ����Ҫ������� ����Ҫ��������߿�£
		{
			left_sum = res;
			cross_low = i;
		}
	}//for int i

	res = 0;
	int right_sum = mini;
	for (int i = mid + 1; i <= high; i++)
	{
		res += num[i];
		if (res > right_sum)
		{
			right_sum = res;
			cross_high = i;
		}
	}

	return right_sum + left_sum;
}

int find_max_subarray(int low, int high,int & max_low,int & max_high)	//max_low max_highΪ���մ𰸵������±�
{
	if (high == low)
	{
		max_low = max_high = low;
		return num[high];
	}

	int mid = (low + high) / 2;
	int left_low, left_high, left_sum;
	int right_low, right_high, right_sum;
	int cross_low, cross_high, cross_sum;

	left_sum = find_max_subarray(low, mid,left_low,left_high);
	right_sum = find_max_subarray(mid + 1, high,right_low,right_high);
	cross_sum = find_cross_subarray(low, high, cross_low, cross_high);

	if (left_sum >= cross_sum && left_sum >= right_sum)
	{
		max_low = left_low;
		max_high = left_high;
		return left_sum;
	}

	if (cross_sum >= left_sum && cross_sum >= right_sum)
	{
		max_low = cross_low;
		max_high = cross_high;
		return cross_sum;
	}

	max_low = right_low;
	max_high = right_high;
	return right_sum;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum, length,seq = 0;
	cin >> casenum;
	while (casenum--)
	{
		if (seq != 0)
			cout << endl;
		cin >> length;
		for (int i = 0; i < length; i++)
			cin >> num[i];
		
		int max_low, max_high, res;
		res = find_max_subarray(0, length - 1, max_low, max_high);
		cout << "Case " << ++seq << ":" << endl;
		cout << res << " " << max_low + 1<< " " << max_high + 1<<endl;
	}
	return 0;
}

//dp
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

using namespace std;
const int maxn = 100000 + 10;

int num[maxn], dp[maxn];//dp[i] ��ʾ�ӿ�ʼ�� ��i���ڵ������Ӵ������ֵ ����dp[i] = maxn(dp[i], dp[i - 1] + num[i])

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum, length, seq = 0;
	cin >> casenum;
	while (casenum--)
	{
		if (0 != seq)
			cout << endl;

		int res , end = 0, start = 0;
		cin >> length;
		for (int i = 0; i < length; i++)
		{
			cin >> num[i];
			dp[i] = num[i];
		}

		res = dp[0];
		for (int i = 1; i < length; i++)
		{
			dp[i] = max(dp[i], dp[i - 1] + num[i]);
			if (res < dp[i])
			{
				res = dp[i];
				end = i;
			}
		}

		//��endλ�ó���������ҵ�start λ��ʹ�� dp[i] = num[start] + ... + num[end]
		int temp = 0;
		for (int i = end; i >= 0; i--)
		{
			temp += num[i];
			if (temp == res)
			{
				start = i;
				//break;
			}
		}

		cout << "Case " << ++seq << ":"<<endl;
		cout << res << " " << start + 1 << " " << end + 1 << endl;
	}//while
	return 0;
}