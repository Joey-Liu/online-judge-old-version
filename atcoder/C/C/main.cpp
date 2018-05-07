#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;
typedef long long LL;

const int maxn = 200000 + 50;
LL nums[maxn], N, pre_sum[maxn], res;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> nums[i];
	
	pre_sum[0] = nums[0];
	for (int i = 1; i < N; i++)
		pre_sum[i] = pre_sum[i - 1] + nums[i];

	LL mini = 0x7fffffff, summ = pre_sum[N - 1];
	for (int i = 0; i < N - 1; i++)
	{
		LL tmp_1 = summ - pre_sum[i];
		LL tmp_2 = pre_sum[i];
		if (abs(tmp_1 - tmp_2) < mini)
		{
			mini = abs(tmp_1 - tmp_2);
		}
	}
	cout << mini << endl;
	return 0;
}