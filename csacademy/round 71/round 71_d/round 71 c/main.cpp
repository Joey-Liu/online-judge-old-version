#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

map<int,int> tab;
int N, ret = 0, ma = -1;

void find_upper_bound()
{
	int val = tab.rbegin()->first;
	int freq = tab.rbegin()->second;
	while (freq < ma)
	{
		freq = freq * 2 + tab[val - 1];
		ret += freq;
		val--;
	}
}

int work()
{
	int val = tab.rbegin()->first;
	int cur = tab.rbegin()->second;
	int cnt = 0;

	while (cnt < ret) //减小上界
	{
		int finished = val;
		int tmp = cnt;//这一局次数

		for (auto it = tab.rbegin(); it != tab.rend() && tmp < ret; it++) //tmp < res_uper_bound
		{
			if (it->first >= finished || it->second <= cur)
				continue;
			if (it->first == 1)
			{
				tmp = INT_MAX;
				break;
			}

			tmp += (it->second - cur);
			int x = (it->second - cur) * 2 + tab[it->first - 1];
			int v = it->first - 1;

			while (tmp < ret && x > cur)
			{
				tmp += (x - cur);
				x = (x - cur) * 2 + tab[v - 1];
				v--;
			} 
			finished = v;
		}//for

		ret = min(ret, tmp);
		val--;
		cnt += cur;
		cur = cur * 2 + tab[val];
	}//while
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int  t;
		cin >> t;
		tab[t]++;
		ma = max(ma, tab[t]);
	}
	int last = tab.rend()->second;
	if (tab[last] >= ma)
	{
		cout << 0 << endl;
		return 0;
	}


	find_upper_bound();
	work();
	cout << ret << endl;
	return 0;
}