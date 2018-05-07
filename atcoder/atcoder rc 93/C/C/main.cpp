#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

const int maxn = 100000 + 50;

int coor[maxn];
int N, scost;

int work(int x)
{
	int res = scost;
	int y = x + 1, z = x - 1;
	if (x == N)
		y = 0;

	res -= abs(coor[z] - coor[x]);
	res -= abs(coor[x] - coor[y]);
	res += abs(coor[z] - coor[y]);
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> coor[i];

	for (int i = 1; i <= N; i++)
		scost += abs(coor[i] - coor[i - 1]);
	scost += abs(coor[N]);

	for (int i = 1; i <= N; i++)
	{
		int res = work(i);
		cout << res << endl;
	}
	return 0;
}