#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int maxn = 10000 + 1000;
int marble[maxn], n, q, num, kasenum = 0;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (2 == scanf("%d%d", &n, &q))
	{
		if (!n && !q)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d", &marble[i]);

		bool flag = false;
		sort(marble, marble + n);
		int mid = 0, lp = 0, rp = n - 1;

		printf("CASE# %d:\n", ++kasenum);
		for (int i = 0; i < q; i++)
		{
			scanf("%d", &num);
			lp = 0; rp = n - 1;
			mid = (lp + rp) / 2;
			flag = false;
			while (lp < rp - 1)
			{
				mid = (lp + rp) / 2;
				if (marble[mid] > num)
					rp = mid - 1;
				else if (marble[mid] < num)
					lp = mid + 1;
				else
					break;
			}

			int index;
			if (marble[mid] == num)
			{
				flag = true;
				index = mid;
			}
			if (marble[lp] == num)
			{
				flag = true;
				index = lp;
			}
			if (marble[rp] == num)
			{
				flag = true;
				index = rp;
			}
			while (flag && index - 1 >= 0 && marble[index - 1] == marble[index])
				index--;

			if (!flag)
				printf("%d not found\n", num);
			else
				printf("%d found at %d\n", num, index + 1);

		}//for

	}//while
	return 0;
}