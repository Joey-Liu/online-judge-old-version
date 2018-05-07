#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
#include <sstream>

using namespace std;
string str, word;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	set<string> dict;
	while (cin >> str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (isalpha(str[i]))
				str[i] = tolower(str[i]);
			else
				str[i] = ' ';
		}
		stringstream ss(str);
		while (ss >> word)
			dict.insert(word);
	}//while

	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
		cout << *it << endl;
	return 0;
}