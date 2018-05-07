#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e+5 + 10;
const int MOD = 1e+9 + 7;
int fact[maxn] = { 0 };
int N, t;

long long mypow(long long a, int p)
{
	long long r = 1;
	while (p)
	{
		if (p & 1)
			r = 1LL * r * a % MOD;
		p = p >> 1;
		a = 1LL* a * a % MOD;
	}
	return r;
}

void init()
{
	fact[0] = 1;
	for (int i = 1; i < maxn; i++)
		fact[i] = 1LL * i * fact[i - 1] % MOD;
}


map<int, int> table;
vector<int> vi;

int main()
{
	init();
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		table[t]++;
	}

	int mx = -1, index = -1, idx = 0;

	for (map<int, int>::iterator it = table.begin(); it != table.end(); it++, idx++)
	{
		vi.push_back(it->second);
		if (mx < it->second)
		{
			mx = it->second;
			index = idx;
		}
	}

	long long res = 1;
	t = fact[mx];
	for (int i = 0; i < vi.size(); i++)
	{
		if (index == i)
			continue;
		long long inv_fact = mypow(fact[mx - vi[i]], MOD - 2);
		res = (res * t) % MOD * inv_fact % MOD;
	}
	cout << res << endl;

	return 0;
}