#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>
#include <sstream>

using namespace std;

const int maxn = 200 + 100;
map<string, int> wordsIgnore;
map<string, int> keywords;
struct Title
{
	string words[10000 + 100];
	int wordsNum;

	Title()
	{
		wordsNum = 0;
	}
};

Title titles[maxn];
string str, wtemp;

int wiNum = 0;

string touppercase(string str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);

	return str;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	std::ios::sync_with_stdio(false);
	while (cin >> str)
	{
		if ("::" == str)
			break;
		wordsIgnore[str] = 1;
	}
	
	int titleNum = 0;
	while (getline(cin, str))
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (isalpha(str[i]))
				str[i] = tolower(str[i]);
		}

		stringstream ss(str);
		int index = 0;
		while (ss >> wtemp)
		{
			titles[titleNum].words[index++] = wtemp;
			if (!wordsIgnore[wtemp])
				keywords[wtemp] = 1;
		}
		titles[titleNum++].wordsNum = index;
	}//while getline

	for (map<string, int>::iterator it = keywords.begin(); it != keywords.end(); it++)
	{
		for (int i = 0; i < titleNum; i++)
		{
			for (int j = 0; j < titles[i].wordsNum; j++)
			{
				if (it->first == titles[i].words[j])
				{
					for (int k = 0; k < titles[i].wordsNum; k++)
					{
						if (k != j)
							cout << titles[i].words[k];
						else
							cout << touppercase(titles[i].words[k]);
						if (k != titles[i].wordsNum - 1)
							cout << " ";
					}
					cout << endl;
				}
			}
		}//for int i
	}//for map

	return 0;
}