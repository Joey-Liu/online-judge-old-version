#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

int kase, onum, xnum;
string map[3];

bool isWin(char c)
{
	// row win
	for (int i = 0; i < 3; i++)
	{
		if (map[i][0] == c && map[i][1] == c && map[i][2] == c)
			return true;
	}

	for (int j = 0; j < 3; j++)
	{
		if (map[0][j] == c && map[1][j] == c && map[2][j] == c)
			return true;
	}

	if (map[0][0] == c &&map[1][1] == c && map[2][2] == c)
		return true;
	if (map[0][2] == c &&map[1][1] == c && map[2][0] == c)
		return true;

	return false;
}

bool isLegal()
{
	if (onum > xnum)
		return false;
	if (xnum - onum > 1)
		return false;
	if (isWin('X') && isWin('O'))
		return false;
	if (isWin('O') && onum != xnum)
		return false;
	if (isWin('X') && xnum == onum)
		return false;
	return true;
}

int main()
{
	freopen("in17.txt", "r", stdin);
	freopen("out17.txt", "w", stdout);
	cin >> kase;
	for (int kasecount = 0; kasecount < kase; kasecount++)
	{
		if (kasecount != 0)
			printf("\n");
		
		for (int i = 0; i < 3; i++)
			cin >> map[i];
		
		xnum = onum = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (map[i][j] == 'O')
					onum++;
				else if (map[i][j] == 'X')
					xnum++;
				else
					continue;
			}
		}

		if (isLegal())
			printf("yes");
		else
			printf("no");
	}//kase

	return 0;
}