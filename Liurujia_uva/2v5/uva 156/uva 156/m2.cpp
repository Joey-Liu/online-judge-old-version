#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
string word;
map<string, int> dict;
set<string> wordset;

string str_sort(string & str)
{
	string s;
	for (int i = 0; i < str.size(); i++)
		s += tolower(str[i]);
	sort(s.begin(), s.end());
	return s;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> word)
	{
		if (word == "#")
			break;
		dict[str_sort(word)] += 1;
		wordset.insert(word);
	}
	
	for (set<string>::iterator it = wordset.begin(); it != wordset.end(); it++)
	{
		string s = *it;
		if (dict[str_sort(s)] == 1)
			cout << s << endl;
	}
	return 0;
}