/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int maxn = 100 + 20;
int num[maxn], n,k;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int  ans = 0,tmp,kind;
	while (cin >> n)
	{
		memset(num, 0, sizeof(num));
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			num[tmp]++;
		}
		cin >> k;

		sort(num + 1, num + n + 1);
		tmp = 0; kind = 0; ans = 0;
		for (int i = 1; i < maxn; i++)
		{
			if (num[i] != 0)
				kind++;
		}


		for (int i = n; i > 0; i--)
		{
			if (num[i] == 0)		//没有这个数
				continue;
			
			tmp += num[i];
			ans++;
			if (tmp == k)
				break;
			if (tmp > k)
			{
				ans--;
				break;
			}
		}
		cout <<kind - ans << endl;
	}
	return 0;
}
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

const int maxn = 120;

int n, k, tmp,kind,num[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> n)
	{
		memset(num, 0, sizeof(num));
		kind = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			num[tmp]++;
		}

		cin >> k;
		for (int i = 0; i < maxn; i++)
		{
			if (num[i] > 0)
				kind++;
		}

		if (n - kind >= k)
			cout << kind << endl;
		else
			cout << n - k << endl;
	}//while
}