#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 1000000 + 200;

typedef long long LL;
LL A[maxn], B[maxn], res;
int N, M;

bool cmp(LL a, LL b)
{
	return a > b;
}

void work()
{
	for (int i = 1; i < N; i++)
	{
		A[i] += A[i - 1];
		B[i] += B[i - 1];
	}

	res = 0;
	for (int i = 0; i < N; i++)
	{
		LL t = B[i] - A[i];
		if (2 == i % 3)
			t = t + (i + 1) / 3 * M;
		res = max(t, res);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (cin >> N >> M)
	{
		res = 0;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < N; i++)
			cin >> B[i];


		sort(A, A + N);
		sort(B, B + N, cmp);
		work();
		cout << res << endl;
	}//while
}