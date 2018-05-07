#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <stdlib.h>

using namespace std;

typedef long long LL;
const int maxn = 1e+5 + 100;

int N, M;

LL a[maxn], b[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < M; i++)
		cin >> b[i];

	LL i = 0, j = 0, res =0;
	LL sa = a[0], sb = b[0];
	while (i < N && j < M)
	{
		if (sa == sb)
		{
			i++;
			j++;
			res += 1;
			sa = a[i];
			sb = b[j];
		}
		else if (sa < sb)
		{
			i++;
			sa += a[i];
		}
		else
		{
			j++;
			sb += b[j];
		}
	}

	cout << res<< endl;

	return 0;
}