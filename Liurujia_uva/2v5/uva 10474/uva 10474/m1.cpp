#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 1e+6;

int marble[maxn];

int biSearch(int lp, int rp, int target)
{
	int mid = (lp + rp) / 2;
	while (lp < rp)
	{
		if (marble[mid] < target)
			lp = mid + 1;
		else if (marble[mid] > target)
			rp = mid - 1;
		else
			return mid;
		mid = (lp + rp) / 2;
	}
	return lp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	int Q, N;
	while (cin >> N >> Q)
	{
		if (!Q && !N)
			break;
		for (int i = 0; i < N; i++)
			cin >> marble[i];
		sort(marble, marble + N);
		int target = 0;

		cout << "CASE# " << ++kasenum << ":" << endl;
		for (int i = 0; i < Q; i++)
		{
			cin >> target;
			int res = biSearch(0, N - 1, target);
			if (marble[res] == target)
			{
				while (res > 0 && marble[res - 1] == marble[res])
					res--;
				cout << target << " found at " << res + 1 << endl;
			}
			else
				cout << target << " not found" << endl;
		}
	}//while
	return 0;
}