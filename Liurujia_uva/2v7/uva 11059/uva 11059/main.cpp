#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long LL;

const int maxn = 20;

int N, num[maxn];
LL res = 0;

LL work(int st, int ed)
{
	LL r = 1;
	for (int i = st; i <= ed; i++)
		r = r * num[i];
	return r;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum = 0;
	while (cin >> N && N)
	{
		for (int i = 0; i < N; i++)
			cin >> num[i];
		
		res = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < N; j++)
			{
				LL tmp = work(i, j);
				if (tmp > res)
					res = tmp;
			}
		}
		cout << "Case #" << ++kasenum << ": The maximum product is " << res << ".\n\n";
	}
	return 0;
}