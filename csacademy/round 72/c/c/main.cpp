#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int maxn = 3e+5;
const int INFINITE = 0x3f3f3f3f;

vector<int> A[maxn];
int row_s[maxn], col_s[maxn], sum;
int N, M;


void work()
{
	int roma = max(row_s[0], row_s[N - 1]);
	int romi = INFINITE;

	for (int i = 1; i < N - 1; i++)
		romi = min(romi, row_s[i]);
	int a = roma * 2 - romi;

	int coma = max(col_s[0], col_s[M - 1]);
	int comi = INFINITE;

	for (int j = 1; j < M - 1; j++)
		comi = min(comi, col_s[j]);
	int b = coma * 2 - comi;

	if (max(a, b) < 0)
		return;

	if (a > b)
		sum = sum - romi / 2 + roma;
	else
		sum = sum - comi / 2 + coma;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		A[i].resize(M);
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
			if (0 == j || M - 1 == j)
				row_s[i] += A[i][j];
			else
				row_s[i] += A[i][j] * 2;
		}
		if (i != 0 && i != N - 1)
			row_s[i] *= 2;
		sum += row_s[i];
	}

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (0 == i || N - 1 == i)
				col_s[j] += A[i][j];
			else
				col_s[j] += 2 * A[i][j];
		}//for int i
		if (0 != j && M - 1 != j)
			col_s[j] *= 2;
	}//for int j
	work();
	cout << sum << endl;
	return 0;
}