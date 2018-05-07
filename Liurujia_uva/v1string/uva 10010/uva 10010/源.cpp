#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>

using namespace std;

const int maxn = 50;
int m, n, wordnum, wordlength, rr, rc;
string str[maxn], words[maxn], curWord;
bool vis[maxn][maxn], found = false;

int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool inMap(int r, int c)
{
	if (r >= m || r < 0 || c >= n || c < 0)
		return false;
	return true;
}

//level 当前需要去查询的字母位置(基于0)
/*
void dfs(int level, int curr, int curc)
{
	if (level == wordlength)
	{
		found = true;
		return;
	}
	int nexr, nexc;
	for (int i = 0; i < 8; i++)
	{
		nexr = curr + dr[i]; nexc = curc + dc[i];
		if (inMap(nexr, nexc) && !vis[nexr][nexc] && 
			(curWord[level] == str[nexr][nexc]))
		{
			vis[nexr][nexc] = true;
			dfs(level + 1, nexr, nexc);
			vis[nexr][nexc] = false;
		}
		if (found)
			return;
	}//for
}
*/

void search(int curr, int curc)
{
	int i, j;
	int orr = curr, orc = curc;

	for (i = 0; i < 8; i++)
	{
		for (j = 1; j < curWord.length(); j++)
		{
			int nexr = curr + dr[i], nexc = curc + dc[i];
			if (inMap(nexr, nexc) && str[nexr][nexc] == curWord[j])
			{
				curr = nexr;
				curc = nexc;
			}
			else
				break;
		}
		if (j == curWord.length())
		{
			found = true;
			break;
		}
		curr = orr, curc = orc;
	}
}

void inputwork()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> str[i];
	cin >> wordnum;
	for (int i = 0; i < wordnum; i++)
		cin >> words[i];
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			str[i][j] = tolower(str[i][j]);
	}
	for (int i = 0; i < wordnum; i++)
	{
		for (int j = 0; j < words[i].length(); j++)
			words[i][j] = tolower(words[i][j]);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--)
	{
		inputwork();
		for (int k = 0; k < wordnum; k++)
		{
			wordlength = words[k].length();
			memset(vis, false, sizeof(vis));
			found = false;
			curWord = words[k];

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (str[i][j] == words[k][0])
					{
						/*
						memset(vis, false, sizeof(vis));
						vis[i][j] = true;
						dfs(1, i, j);
						vis[i][j] = false;
						*/
						search(i, j);
					}
					if (found)
					{
						rr = i, rc = j;
						break;
					}
				}
				if (found)
					break;
			}
			cout << rr + 1<< " " << rc+1 << endl;
		}//for wordnum
		if (kasenum != 0)
			cout << endl;
	}//while kasenum--
	return 0;
}
