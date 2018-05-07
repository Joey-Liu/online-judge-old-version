#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

string str;
map<string, int> record;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	while (cin >> casenum && casenum != 0)
	{
		record.clear();
		int max = 0;
		string ans;

		for (int i = 0; i < casenum; i++)
		{
			cin >> str;
			record[str]++;
		}

		for (map<string, int>::iterator it = record.begin(); it != record.end(); it++)
		{
			if ((*it).second > max)
			{
				ans = (*it).first;
				max = (*it).second;
			}
		}

		cout << ans << endl;
	}//while
}