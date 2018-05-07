#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sstream>
#include <map>

using namespace std;
map<string, int> conquest;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	char c;
	int kase;
	string str, country;
	stringstream ss;
	cin >> kase;
	cin.get(c);

	for (int i = 0; i < kase; i++)
	{
		getline(cin, str);
		ss << str;
		ss >> str;
		conquest[str]++;
		ss.clear();
		ss.str("");
	}

	for (map<string, int>::iterator it = conquest.begin(); it != conquest.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}