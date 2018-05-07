#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sstream>
#include <set>

using namespace std;
const int maxn = 6000;
char line[maxn];
char temp[300];
int wordsNum = 0;
set<string> wordsSet;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (gets(line))
	{
		for (int i = 0; i < strlen(line); i++)
		{
			if (isalpha(line[i]))
				line[i] = tolower(line[i]);
			else
				line[i] = ' ';
		}

		stringstream ss(line);
		while (ss >> temp)
		{
			string str(temp);
			if (!wordsSet.count(temp))
				wordsSet.insert(str);
		}
	}//while gets
	
	for (set<string>::iterator it = wordsSet.begin(); it != wordsSet.end(); it++)
		cout << *it << endl;
	return 0;
}