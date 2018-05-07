#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 20;

struct Node
{
	int st, ed, cnt;
	Node()
	{
		st = -1;
		ed = -1;
		cnt = -1;
	}
};

bool cmp(const Node  a, const Node  b)
{
	return a.cnt < b.cnt;
}

vector<Node> vn;
bool exist[maxn];

string str, s;
int N, M, num;

int work()
{
	int change = 0;
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] != s[i + 1])
			change++;
	}
	if (change <= M)
		return s.size();

	bool flag = false;
	if ('b' == s[s.size() - 1])
		flag = true;

	int tail = s.size() - 1;
	while ('b' == s[tail])
		tail--;
	Node node;
	if (flag)
	{
		node.st = tail + 1;
		node.ed = s.size() - 1;
		node.cnt = node.ed - node.st + 1;
	}

	int ind = 0;
	int state = 0, prev = 0;
	while (ind <= tail)
	{
		if (0 == state && 'a' == s[ind])
			ind++;
		else if (0 == state && 'b' == s[ind])
		{
			state = 1;
			prev = ind;
			ind++;
		}
		else if (1 == state && 'a' == s[ind])
		{
			Node nod;
			nod.cnt = ind - prev;
			vn.push_back(nod);
			state = 0;
		}
		else
			ind++;
	}

	sort(vn.begin(), vn.end(), cmp);
	int di = change - M;
	int r1 = s.size(), r2 = s.size(), res;
	
	if (flag)
	{
		di--;
		r1 -= node.cnt;
		if (di > 0)
		{
			for (int i = 0; i < vn.size(); i++)
			{
				r1 -= vn[i].cnt;
				di -= 2;
				if (di <= 0)
					break;
			}
		}
		res = r1;

		di = change - M;
		for (int i = 0; i < vn.size(); i++)
		{
			di -= 2;
			r2 -= vn[i].cnt;
			if (di <= 0)
				break;
		}
		if (di <= 0)
			res = max(res, r2);
		return res;
	}
	else
	{
		int res = s.size();
		int di = change - M;
		for (int i = 0; i < vn.size(); i++)
		{
			res -= vn[i].cnt;
			di -= 2;
			if (di <= 0)
				break;
		}
		return res;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N >> M)
	{
		cin >> str;
		int ind = 0;
		for (ind = 0; ind < str.size(); ind++)
		{
			if (str[ind] != 'b')
				break;
		}
		
		if (ind == str.size())
		{
			cout << 0 << endl;
			return 0;
		}
		s = str.substr(ind);
		int r = work();
		cout << r << endl;
	}
}