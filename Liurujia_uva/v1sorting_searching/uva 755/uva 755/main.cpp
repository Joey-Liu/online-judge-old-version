#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

map<string, long long int> telenumber;

string convert(const string & s)
{
	string str = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '-')
			continue;

		if (s[i] >= 'A' && s[i] <= 'O')
			str += ('0' + (s[i] - 'A') / 3) + 2;
		else if ('P' == s[i] || 'R' == s[i] || 'S' == s[i])
			str += '7';
		else if (s[i] >= 'T' && s[i] <= 'Y')
			str += (s[i] + 2 - 'A') / 3 + 1 + '0';
		else
			str += s[i];
	}
	str.insert(3, "-");

	return str;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum, telelength;
	string st, sres;
	cin >> kasenum;
	while (kasenum--)
	{
		telenumber.clear();
		cin >> telelength;

		for (int i = 0; i < telelength; i++)
		{
			cin >> st;
			telenumber[convert(st)]++;
		}
		bool flag = true;
		map<string, long long int>::iterator it;
		for (it = telenumber.begin(); it != telenumber.end(); it++)
		{
			if (it->second > 1)
			{
				flag = false;
				cout << it->first << " " << it->second << endl;
			}
		}
		if (true == flag)
			cout << "No duplicates." << endl;
		if (kasenum)
			cout << endl;
	}//while

	return 0;
}