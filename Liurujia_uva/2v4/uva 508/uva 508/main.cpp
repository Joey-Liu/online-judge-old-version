#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#include <memory.h>


using namespace std;

map<char, string> morse;
map<string, string> dict;

#define MAXN 0x3f3f3f3f

int word_compare(string s1, string s2)
{
	if (s1 == s2)
		return 0;
	
	if (s1.length() < s2.length())
		swap(s1, s2);
	if (s1.substr(0, s2.length()) == s2)
		return s1.length() - s2.length();
	else
		return MAXN;
}

string work(string morse_code)
{
	string res_str;
	int perfect_num = 0, diff = MAXN;
	for (map<string, string>::iterator it = dict.begin(); it != dict.end(); it++)
	{
		int r = word_compare(morse_code, it->second);
		if (!r)
		{
			perfect_num++;
			res_str = it->first;
		}
		else if (!perfect_num && r <= diff)
		{
			res_str = it->first;
			diff = r;
		}
	}
	if (perfect_num > 1)
		res_str += '!';
	if (0 == perfect_num)
		res_str += '?';
	return res_str;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	char mor;
	string str, word;
	while (cin >> mor && '*' != mor)
	{
		cin >> str;
		morse[mor] = str;
	}

	while (cin >> word && word[0] != '*')
	{
		str = "";
		for (int i = 0; i < word.size(); i++)
			str += morse[word[i]];
		dict[word] = str;
	}
	while (cin >> str && '*' != str[0])
		cout << work(str) << endl;

	return 0;
}