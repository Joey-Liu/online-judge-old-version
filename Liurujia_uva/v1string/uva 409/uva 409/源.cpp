#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory>

using namespace std;

int knum, enumber;
const int maxn = 20 + 10;
string keywords[maxn], execuses[maxn], ori[maxn];
int cnt[maxn];

void read()
{
	for (int i = 0; i < knum; i++)
		cin >> keywords[i];
	getchar();
	for (int i = 0; i < enumber; i++)
	{
		getline(cin, execuses[i]);
		ori[i] = execuses[i];
	}
	for (int i = 0; i < enumber; i++)
	{
		for (int j = 0; j < execuses[i].length(); j++)
		{
			if (isalpha(execuses[i][j]))
				execuses[i][j] = tolower(execuses[i][j]);
			else
				execuses[i][j] = ' ';
		}
	}
}

bool validSep(char ch)
{
	if (ch == ' ' || ',' == ch || '.' == ch || '?' == ch || '!' == ch)
		return true;
	return false;
}

void search()
{
	for (int i = 0; i < enumber; i++)
	{
		for (int j = 0; j < knum; j++)
		{
			int start = 0, pos = 0;
			while (true)
			{
				pos = execuses[i].find(keywords[j], start);
				if (pos == string::npos)
					break;
				int endPos = pos + keywords[j].length();
				if (endPos >= execuses[i].length() || validSep(execuses[i][endPos]))
				{
					if (0 == start || validSep(execuses[i][start - 1]))
						cnt[i]++;
				}
;
				start = pos + keywords[j].length();
			}
		}
	}//for enumber
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kase = 0;
	while (cin >> knum >> enumber)
	{
		read();
		memset(cnt, 0, sizeof(cnt));
		search();

		int cntMax = -1;
		for (int i = 0; i < enumber; i++)
		{
			if (cntMax < cnt[i])
				cntMax = cnt[i];
		}
		
		cout << "Excuse Set #" << ++kase << endl;
		for (int i = 0; i < enumber; i++)
		{
			if (cntMax == cnt[i])
				cout << ori[i] << endl;
		}
		cout << endl;
	}//while

	return 0;
}