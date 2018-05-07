#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
#include <vector>

using namespace std;
const int maxn = 50 + 10;

string tab[maxn];
set<int> cols[maxn];
vector<set<int> > vs;

int R, C;

bool has_intersection(set<int> s1, set<int> s2)
{
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		if (s2.count(*it))
			return true;
	}
	return false;
}

int try_push(set<int> si)
{
	for (int i = 0; i < vs.size(); i++)
	{
		set<int> t = vs[i];
		if (t == si)
			return 1;
		if (has_intersection(si, t))
			return 0;
	}
	return 2;
}

bool work()
{
	for (int i = 0; i < R; i++)
	{
		set<int> si;
		for (int j = 0; j < C; j++)
		{
			if ('#' == tab[i][j])
				si.insert(j);
		}
		
		int state = try_push(si);
		if (!state)
			return false;
		else if (2 == state)
			vs.push_back(si);
	}//for int i
	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> tab[i];
	if (work())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}