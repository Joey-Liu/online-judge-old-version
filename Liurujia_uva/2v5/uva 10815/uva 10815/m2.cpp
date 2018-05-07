#define _LOCAL

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;
const int maxn = 200 + 50;
char line[maxn];
string str, ss, word;
set<string> words;

int main()
{
#ifdef _LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	while (getline(cin, str))
	{
		ss = "";
		for (int i = 0; i < str.size(); i++)
		{
			if (isalpha(str[i]))
				ss += tolower(str[i]);
			else
				ss += ' ';
		}
		stringstream tstrss(ss);
		while (tstrss >> word)
			words.insert(word);
	}
	for (set<string>::iterator it = words.begin(); it != words.end(); it++)
		cout << *it << endl;
	return 0;
}