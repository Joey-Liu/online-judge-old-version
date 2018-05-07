#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 256 * 2 + 50;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int depth, query, kasenum = 0, index[10];
	string str, leaves;
	char ch;
	while (cin >> depth && depth)
	{
		for (int i = 0; i < depth; i++)
			cin >> ch >> index[i];
		cin >> leaves >> query;

		int prefix = 1;
		for (int i = 0; i < depth; i++)
			prefix = (prefix << 1);

		cout << "S-Tree #" << ++kasenum << ":" << endl;
		for (int i = 0; i < query; i++)
		{
			cin >> str;
			string real_str = str;
			for (int i = 0; i < str.size(); i++)
				real_str[i] = str[index[i] - 1];

			int idx = 1;
			for (int j = 0; j < str.size(); j++)
			{
				idx = (idx << 1);
				if ('1' == real_str[j])
					idx++;
			}
			idx -= prefix;
			cout << leaves[idx];
		}
		cout << endl << endl;
	}//while cin
	return 0;
}