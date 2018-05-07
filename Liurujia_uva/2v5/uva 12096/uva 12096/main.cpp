#define _LOCAL
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <iterator>

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

using namespace std;

typedef set<int> Set;
stack<int> sstack;
vector<Set> set_arr;
map<Set, int> set2num;


int ID(Set se)
{
	if (set2num.count(se))
		return set2num[se];
	set_arr.push_back(se);
	set2num[se] = set_arr.size() - 1;
	return set2num[se];
}

int main()
{
#ifdef _LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int kasenum = 0, order_num;
	cin >> kasenum;
	string order;
	while (kasenum--)
	{
		cin >> order_num;
		set2num.clear();
		set_arr.clear();
		while (!sstack.empty())
			sstack.pop();

		sstack.push(ID(Set()));
		for (int i = 0; i < order_num; i++)
		{
			cin >> order;
			if (order[0] == 'P')
				sstack.push(ID(Set()));
			else if (order[0] == 'D')
				sstack.push(sstack.top());
			else
			{
				Set s1 = set_arr[sstack.top()]; sstack.pop();
				Set s2 = set_arr[sstack.top()]; sstack.pop();
				Set se;
				if (order[0] == 'U')
					set_union(ALL(s1), ALL(s2), INS(se));
				if (order[0] == 'I')
					set_intersection(ALL(s1), ALL(s2), INS(se));
				if (order[0] == 'A')
				{
					se = s2;
					se.insert(set2num[s1]);
				}
				sstack.push(ID(se));
			}//else
			cout << set_arr[sstack.top()].size() << endl;
		}//for int i
		cout << "***" << endl;
	}//while
	return 0;
}