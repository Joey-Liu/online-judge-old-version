#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 30;

set<int> children[maxn];
bool exist[maxn], vis[maxn];
int node_num = 0;
int bandwidth = 0x3f3f3f3f;
int res[maxn], t_res[maxn];

void dfs(int layer, int t_bandwidth)
{
	if (layer == node_num && t_bandwidth < bandwidth)
	{
		for (int i = 0; i < node_num; i++)
			res[i] = t_res[i];
		bandwidth = t_bandwidth;
		return;
	}

	for (int i = 0; i < maxn; i++)
	{
		if (!exist[i] || vis[i])
			continue;

		vis[i] = true;
		t_res[layer] = i;
		bool flag = true;
		int node_bandwidth = 0;
		//¼ÆËã´ø¿í
		for (int j = 0; j < layer; j++)
		{
			if (children[i].find(t_res[j]) != children[i].end())
			{
				int k = layer - j;
				if (k > bandwidth)
				{
					flag = false;
					break;
				}
				if (k > node_bandwidth)
					node_bandwidth = k;
			}
		}//for int j

		if (flag)
		{
			t_bandwidth = max(node_bandwidth, t_bandwidth);
			dfs(layer + 1, t_bandwidth);
		}
		vis[i] = false;
	}//for int i
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	string str;
	while (cin >> str)
	{
		if ('#' == str[0])
			break;

		memset(exist, false, sizeof(exist));
		memset(vis, false, sizeof(vis));
		
		for (int i = 0; i < maxn; i++)
			children[i].clear();
		
		int idx = 0;
		while (idx < str.size())
		{
			if (';' == str[idx])
				idx++;
			int node = str[idx] - 'A';
			exist[node] = true;
			idx += 2;
			while (idx < str.size() && str[idx] != ';')
			{
				exist[str[idx] - 'A'] = true;
				children[node].insert(str[idx] - 'A');
				children[str[idx] - 'A'].insert(node);
				idx++;
			}
		}//while idx

		node_num = 0;
		for (int i = 0; i < maxn; i++)
			if (exist[i])
				node_num++;

		bandwidth = 0x3f3f3f3f;
		dfs(0, 0);
		
		for (int i = 0; i < node_num; i++)
			cout << char(res[i] + 'A') << " ";
		cout << "-> ";
		cout << bandwidth << endl;
	}//while cinfafdasdfddd>>str
	return 0;
}