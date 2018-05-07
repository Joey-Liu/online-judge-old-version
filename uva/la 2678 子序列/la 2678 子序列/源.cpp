#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
//#include <algorithm>
#define min(x, y) ((x) < (y) ? (x) :(y))

using namespace std;
const int maxn = 100000 + 10;
int b[maxn], a[maxn];
int n, s;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> n >> s)
	{
		int ans = n + 1;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		b[0] = 0;
		for (int i = 1; i <= n; i++)
			b[i] = b[i - 1] + a[i];

		int i = 1;
		for (int j = 1; j <= n; j++)
		{
			if (b[i - 1] > b[j] - s)
				continue;
			while (b[i - 1] <= b[j] - s)
				i++;
			ans = min(j - i + 2, ans);
		}
		cout << (ans == n + 1 ? 0 : ans) << endl;
	}
	return 0;
}