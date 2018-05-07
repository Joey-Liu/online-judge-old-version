#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 1000 + 100;
int N;
int num[maxn];

int bin_find(int goal,int _lp,int _rp)		//need to point out the limit
{
	int lp = _lp;
	int rp = N - 1;

	int mid = (lp + rp) / 2;
	while (lp + 1 < rp)
	{
		if (num[mid] == goal)
			return mid;

		if (num[mid] < goal)
			lp = mid + 1;
		else if (num[mid] > goal)
			rp = mid - 1;

		mid = (rp + lp) / 2;
	}
	if (num[lp] == goal)
		return lp;
	if (num[rp] == goal)
		return rp;

	return -1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &N))
	{
		bool hasFind = false;
		for (int i = 0; i < N; i++)
			scanf("%d", &num[i]);

		sort(num, num + N);
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				int ans = -(num[i] + num[j]);
				int res = bin_find(ans,j + 1,N - 1);
				if (-1 != res)
				{
					cout << num[i] << " " << num[j] << " " << num[res] << endl;
					hasFind = true;
				}
			}// for int j
		}// for int i

		if (!hasFind)
			cout << "Ren Chou Jiu Gai Duo Du Shu!" << endl;
	}
	return 0;
}