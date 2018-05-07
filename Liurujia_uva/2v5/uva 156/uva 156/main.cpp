#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> dict;
vector<string> wos, res_wos;

string str_repr(const string & str)
{
	string res = str;
	for (int i = 0; i < res.size(); i++)
		res[i] = tolower(res[i]);
	sort(res.begin(), res.end());
	return res;
}

string word;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> word)
	{
		if ('#' == word[0])
			break;
		
		wos.push_back(word);
		string srep = str_repr(word);
		if (0 == dict.count(srep))
			dict[srep] = 0;
		dict[srep]++;
	}


	for (int i = 0; i < wos.size(); i++)
	{
		word = wos[i];
		if (dict[str_repr(word)] == 1)
			res_wos.push_back(word);
	}
	sort(res_wos.begin(), res_wos.end());

	for (int i = 0; i < res_wos.size(); i++)
		cout << res_wos[i] << endl;

	return 0;
}