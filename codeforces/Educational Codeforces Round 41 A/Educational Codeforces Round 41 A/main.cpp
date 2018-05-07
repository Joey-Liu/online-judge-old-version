#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 50;
int cnt[maxn], N, M;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(cnt, 0, sizeof(cnt));

	cin >> N >> M;
	int t;

	for (int i = 0; i < M; i++)
	{	
		cin >> t;
		cnt[t]++;
	}
	int mini = cnt[1];

	for (int i = 2; i <= N; i++)
		mini = min(mini, cnt[i]);
	cout << mini << endl;
	return 0;
}