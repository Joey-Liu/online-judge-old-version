#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 50 + 20;
char dice[maxn][maxn];
int visitted[maxn][maxn];
int diceNum[maxn], diceBlocks;
int row, col, diretions[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, {1, 0} };
void dfsF(int r, int c);

bool inArea(int r, int c)
{
	if (r < 0 || r > row || c < 0 || c > col)
		return false;
	return true;
}

bool check(int r, int c)
{
	if (dice[r][c] == '*' || dice[r][c] == 'X')
		return true;
	return false;
}

void dfsS(int r, int c)
{
	if (inArea(r, c) && !visitted[r][c] && dice[r][c] == 'X')
	{
		visitted[r][c] = false;
		dice[r][c] = '*';
		for (int i = 0; i < 4; i++)
			dfsS(r + diretions[i][0], c + diretions[i][1]);
		/*for (int i = 0; i < 4; i++)
			dfsF(r + diretions[i][0], c + diretions[i][1]);*/
	}
}

void dfsF(int r, int c)
{
	if (inArea(r, c) && !visitted[r][c] && check(r, c))
	{
		visitted[r][c] = true;
		if (dice[r][c] == 'X')
		{
			visitted[r][c] = false;
			dfsS(r, c);
			diceNum[diceBlocks]++;
			dfsF(r, c);
		}
		else
		{
			for (int i = 0; i < 4; i++)
				dfsF(r + diretions[i][0], c + diretions[i][1]);
		}
	}
}

int main()
{
	freopen("in2.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kaseNum = 0;
	while (cin >> col >> row)
	{
		memset(visitted, false, sizeof(visitted));
		memset(diceNum, 0, sizeof(diceNum));
		diceBlocks = 0;

		if (col <= 0 || row <= 0)
			break;
		for (int i = 0; i < row; i++)
			cin >> dice[i];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if ('*' == dice[i][j] && !visitted[i][j])
				{
					dfsF(i, j);
					if (diceNum[diceBlocks] > 0 && diceNum[diceBlocks] <= 6)
						diceBlocks++;
				}
			}
		}//for int i

		sort(diceNum, diceNum + diceBlocks);
		cout << "Throw " << ++kaseNum << endl;
		for (int i = 0; i < diceBlocks - 1; i++)
			cout << diceNum[i] << " ";
		cout << diceNum[diceBlocks - 1] << endl << endl;
	}//while
	return 0;
}