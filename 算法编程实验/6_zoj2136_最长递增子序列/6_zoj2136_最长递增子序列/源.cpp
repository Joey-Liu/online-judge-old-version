#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 1000 + 10;
int N, num[maxn], B[maxn],len = 0;		//B[i] 存储长度为i的 递增子序列的 最小末尾
int casenum;

int BiSearch(int nu)			//找到 元素num 应该在 B[]数组中的位置
{
	int lp = 0, rp = len - 1;
	int mid = (lp + rp) / 2;
	while (lp + 1 < rp)
	{
		if (B[mid] > nu)
			rp = mid;
		else if (B[mid] < nu)
			lp = mid;
		else
			return mid;

		mid = (lp + rp) / 2;
	}

	if (B[lp] > nu)
		return lp;
	return rp;
}


int LIS()			//返回最长递增子序列的长度
{
	B[0] = num[0];
	len = 1;
	int pos = 0;

	for (int i = 1; i < N; i++)
	{
		if (num[i] > B[len - 1])
			B[len++] = num[i];
		else
		{
			pos = BiSearch(num[i]);
			B[pos] = num[i];
		}
	}

	return len;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> casenum;
	while (casenum--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> num[i];
		cout << LIS()<<endl;
		if (0 != casenum)
			cout << endl;
	}
	return 0;
}