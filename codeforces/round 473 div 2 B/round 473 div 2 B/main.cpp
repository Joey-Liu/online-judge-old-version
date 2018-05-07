#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int N, K, M;

typedef long long LL;

const int maxn = 100000 + 50;
map<string, int> word2id;

LL cost[maxn] = { 0 };

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;
		word2id[str] = i;
	}

	for (int i = 1; i <= N; i++)
		cin >> cost[i];

	for (int i = 0; i < K; i++)
	{
		int nu, tm;
		LL mini_cost = 0x7fffffff;
		cin >> nu;
		vector<int> vi;

		for (int j = 0; j < nu; j++)
		{
			cin >> tm;
			vi.push_back(tm);
			mini_cost = min(mini_cost, cost[tm]);
		}

		for (int j = 0; j < vi.size(); j++)
			cost[vi[j]] = mini_cost;
	}

	LL res = 0;
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		res += cost[word2id[str]];
	}
	cout << res << endl;

	return 0;
}