#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <string>

using namespace std;

typedef set<int> Myset;
vector<Myset> mySetCache;
map<Myset, int> dict;
stack<int> stackComputer;

int mySetId(Myset ms)
{
	if (dict.count(ms))
		return dict[ms];
	mySetCache.push_back(ms);
	return dict[ms] = mySetCache.size() - 1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum, cmdCnt;
	string cmd;
	cin >> kasenum;

	while (kasenum--)
	{
		while (!stackComputer.empty())
			stackComputer.pop();
		dict.clear();
		mySetCache.clear();

		cin >> cmdCnt;
		while (cmdCnt--)
		{
			cin >> cmd;
			if ("PUSH" == cmd)
				stackComputer.push(mySetId(Myset()));
			else if ("DUP" == cmd)
				stackComputer.push(stackComputer.top());
			else
			{
				Myset ms;
				Myset msFirst = mySetCache[stackComputer.top()];
				stackComputer.pop();
				Myset msSecond = mySetCache[stackComputer.top()];
				stackComputer.pop();
				if ("UNION" == cmd)
				{
					set_union(msFirst.begin(), msFirst.end(),
						msSecond.begin(), msSecond.end(), inserter(ms, ms.begin()));
					stackComputer.push(mySetId(ms));
				}
				else if ("INTERSECT" == cmd)
				{
					set_intersection(msFirst.begin(), msFirst.end(), msSecond.begin(), msSecond.end(), inserter(ms, ms.begin()));
					stackComputer.push(mySetId(ms));
				}
				else
				{
					ms = msSecond;
					ms.insert(dict[msFirst]);
					stackComputer.push(mySetId(ms));
				}
			}
			cout << mySetCache[stackComputer.top()].size()<< endl;
		}//while cmdCnt
		cout << "***" << endl;
	}//while kasenum
	return 0;
}