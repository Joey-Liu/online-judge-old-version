#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 10;
int strength;
int a[maxn];
int mini;			//the minimum cost
int w;				//weishu

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &strength))
	{
		mini = 0x3f3f3f3f;
		for (int i = 1; i < maxn; i++)
			scanf("%d", &a[i]);

		for (int i = 1; i < maxn; i++)
		{
			if (mini > a[i])
				mini = a[i];
		}

		w = strength / mini;				//the largest weishu == 
		if (w == 0)
		{
			printf("-1\n");
			continue;
		}

		int ts, tw;
		string ans = "";
		for (tw = w; tw >= 1; tw--)
		{
			for (int i = 9; i >= 1; i--)
			{
				if (strength >= a[i]) 
				{
					ts = strength - a[i];
					if (ts / mini >= tw - 1)
					{
						strength -= a[i];
						ans += ('0' + i);
						break;
					}
				}//if
			}// for int i
		}//for int tw
		cout << ans << endl;
	}//while

	return 0;
}