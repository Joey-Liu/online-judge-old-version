#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100000 + 20;

int va[maxn], vb[maxn];
int N;

void work()
{
	int low_cnt = 0, up_cnt = 0, mid_cnt = 0, mii = va[0] + 1;
	for (int i = 0; i < N; i++)
	{
		if (va[i] == va[0])
			low_cnt++;
		else if (va[i] == va[N - 1])
			up_cnt++;
		else
			mid_cnt++;
	}
	int p = min(low_cnt, up_cnt) * 2;
	int q;
	if (0 == mid_cnt % 2)
		q = mid_cnt;
	else
		q = mid_cnt - 1;

	cout << N - max(p, q) << endl;
	if (p > q)
	{
		cout << mii;
		for (int i = 1; i < mid_cnt + p; i++)
			cout << ' ' << mii;
		if (low_cnt < up_cnt)
		{
			for (int i = 0; i < up_cnt - low_cnt; i++)
				cout << ' ' << va[N - 1];
		}
		else
		{
			for (int i = 0; i < low_cnt - up_cnt; i++)
				cout << ' ' << va[0];
		}
		cout << endl;
	}
	else
	{
		cout << va[0];
		for (int i = 1; i < low_cnt + mid_cnt / 2; i++)
			cout << ' ' << va[0];
		for (int i = 0; i < up_cnt + mid_cnt / 2; i++)
			cout << ' ' << va[N - 1];
		if (mid_cnt % 2)
			cout << ' ' << mii << endl;
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N)
	{
		for (int i = 0; i < N; i++)
			cin >> va[i];
		sort(va, va + N);
		if (1 >= va[N - 1] - va[0])
		{
			cout << N << endl;
			cout << va[0];
			for (int i = 1; i < N; i++)
				cout << ' ' << va[i];
			cout << endl;
		}
		else
		{
			work();
		}
	}
}