#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 10;
LL N, num[maxn];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num, num + N);
	int mini = num[0];
	for (int i = 0; i < N; i++)
		num[i] -= mini;

	int t = num[N / 2];
	LL res = 0;
	for (int i = 0; i < N / 2; i++)
		res = res + t - num[i];
	for (int i = N / 2 + 1; i < N; i++)
		res = res + num[i] - t;
	cout << res << endl;
	return 0;
}