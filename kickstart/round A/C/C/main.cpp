#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <set>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

typedef long long LL;

const int maxn = 20000 + 100;

struct Node
{
	char st, ed;
	multiset<char> sc;
	int len;
};

vector<Node> vn;
bool vis[maxn];
LL x[maxn];


int L, N, A, B, C, D;
char s1, s2;

string gen_str()
{
	string str(N, '0');
	str[0] = s1;
	str[1] = s2;
	x[0] = s1;
	x[1] = s2;

	for (int i = 2; i < N; i++)
	{
		x[i] = 1L * (A * x[i - 1] + B * x[i - 2] + C) % D;
		str[i] = char(97 + (x[i] % 26));
	}
	return str;
}

int work(string str)
{
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < L; i++)
	{
		Node node = vn[i];
		for (int j = 0; j < str.size(); j++)
		{
			int st = j, ed = j + node.len - 1;
			if (ed >= str.size())
				continue;
			if (str[st] != node.st || str[ed] != node.ed)
				continue;

			multiset<char> mc;
			for (int k = st + 1; k < ed; k++)
				mc.insert(str[k]);
			if (mc == node.sc)
			{
				vis[i] = true;
				break;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < L; i++)
		if (vis[i])
			res++;

	return res;
}

int main()
{
	freopen("C-large-practice.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int kasenum = 0, cur = 0;
	cin >> kasenum;
	while (++cur <= kasenum)
	{
		vn.clear();
		cin >> L;
		for (int i = 0; i < L; i++)
		{
			string str;
			cin >> str;
			Node node;
			node.st = str[0];
			node.ed = str[str.size() - 1];
			node.len = str.size();
			for (int i = 1; i < str.size() - 1; i++)
				node.sc.insert(str[i]);
			vn.push_back(node);
		}//for int i

		cin >> s1 >> s2 >> N >> A >> B >> C >> D;
		string str = gen_str();
		int res = work(str);
		cout << "Case #" << cur << ": " << res << endl;
	}//while
	cout << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}