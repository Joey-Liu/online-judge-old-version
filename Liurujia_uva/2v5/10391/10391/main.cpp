#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <set>

using namespace std;

set<string> dict;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string word;
	while (cin >> word)
		dict.insert(word);

	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
	{
		word = *it;
		bool flag = false;
		for (int i = 1; i < (int)word.length(); i++)
		{
			string w1 = word.substr(0, i);
			string w2 = word.substr(i, word.length() - i);
			if (dict.count(w1) && dict.count(w2))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << word << endl;
	}
	return 0;
}