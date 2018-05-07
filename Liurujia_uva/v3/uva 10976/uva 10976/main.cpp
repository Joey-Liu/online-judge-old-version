#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int k, x, y;
	vector<pair<int, int>> ans;
	while (cin >> k)
	{
		int res = 0;
		ans.clear();
		for (int i = 1; i <= 2 * k; i++)
		{
			y = i;
			if (y - k > 0)
			{
				x = k * y / (y - k);
				int te = (k * y) % (y - k);
				if (!te && x >= y)
				{
					res++;
					//printf("1/%d = 1/%d + 1/%d\n", k, x, y);
					ans.push_back(pair<int, int>(x, y));
				}
			}
		}//for
		printf("%d\n", res);
		for (int i = 0; i < ans.size(); i++)
		{
			pair<int, int> pa = ans[i];
			x = pa.first;
			y = pa.second;
			printf("1/%d = 1/%d + 1/%d\n", k, x, y);
		}
	}//while
	return 0;
}