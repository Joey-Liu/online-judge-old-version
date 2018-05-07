#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, int> table;
vector<string> name;

const int maxn = 1e5;

vector<int> installed;
vector<int> depend[maxn], depend2[maxn];

int status[maxn];

int ID(string str)
{
	if (table.count(str))
		return table[str];
	name.push_back(str);
	table[str] = name.size() - 1;
	return table[str];
}

void install(int item, bool toplevel)
{
	if (!status[item])
	{
		for (int i = 0; i < depend[item].size(); i++)
			install(depend[item][i], false);
		cout << "   Installing " << name[item] << "\n";
		status[item] = (toplevel ? 1 : 2);
		installed.push_back(item);
	}
}

bool isNeed(int item)
{
	for (int i = 0; i < depend2[item].size(); i++)
	{
		if (status[depend2[item][i]])
			return true;
	}
	return false;
}


void remove(int item, bool toplevel)
{
	if ((toplevel || status[item] == 2) && !isNeed(item))
	{
		status[item] = 0;
		installed.erase(remove(installed.begin(), installed.end(), item));
		cout << "   Removing " << name[item] << endl;
		for (int i = 0; i < depend[item].size(); i++)
			remove(depend[item][i], false);
	}
}

void list()
{
	for (int i = 0; i < installed.size(); i++)
		cout << "   " << name[installed[i]] << "\n";
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string line, cmd;
	while (getline(cin, line))
	{
		cout << line << "\n";
		stringstream ss(line);

		ss >> cmd;
		string item1, item2;
		if ('E' == cmd[0])
			break;
		else if ('L' == cmd[0])
			list();
		else
		{
			ss >> item1;
			int i1 = ID(item1);
			if ('D' == cmd[0])
			{
				while (ss >> item2)
				{
					int i2 = ID(item2);
					depend[i1].push_back(i2);
					depend2[i2].push_back(i1);
				}
			}
			else if ('I' == cmd[0])
			{
				if (status[i1]) 
					cout << "   " << item1 << " is already installed.\n";
				else 
					install(i1, true);
			}
			else
			{
				if (!status[i1])
					cout << "   " << item1 << " is not installed.\n";
				else if (isNeed(i1))
					cout << "   " << item1 << " is still needed.\n";
				else
					remove(i1, true);
			}//else
		}//else
	}//while
	return 0;
}