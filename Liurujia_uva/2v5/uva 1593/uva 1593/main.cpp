#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 10;

vector<int> pos;
vector<string> codes[maxn];


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string sline, str;
	int lines = 0;
	while (getline(cin, sline))
	{
		stringstream ss(sline);
		while (ss >> str)
			codes[lines].push_back(str);
		lines++;
	}//while

	int max_words = 0;
	for (int i = 0; i < lines; i++)
		max_words = max(max_words, (int)codes[i].size());
	pos.push_back(0);
	int prev_pos = 0, pres_pos = 0;

	for (int j = 0; j < max_words; j++)
	{
		int tm_len = -1;
		for (int i = 0; i < lines; i++)
		{
			if (codes[i].size() <= j)
				continue;
			tm_len = max(tm_len, (int)codes[i][j].length());
		}
		pres_pos = prev_pos + tm_len + 1;
		pos.push_back(pres_pos);
		prev_pos = pres_pos;
	}

	for (int i = 0; i < lines; i++)
	{
		int ind = 0;
		for (int j = 0; j < codes[i].size(); j++)
		{
			while (ind < pos[j])
			{
				cout << " ";
				ind++;
			}
			cout << codes[i][j];
			ind += codes[i][j].size();
		}//for int j
		cout << endl;
	}
	return 0;
}