#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
const int maxn = 10;

int mat[maxn][maxn];
bool nu[maxn];
int casenum;
bool flag = true;

void check()
{
	for (int i = 1; i < maxn; i++)
	{
		memset(nu, false, sizeof(nu));
		for (int j = 1; j < maxn; j++)
		{
			if (mat[i][j] > 9 || mat[i][j] < 1)
			{
				flag = false;
				break;
			}
			if (true == nu[mat[i][j]])
			{
				flag = false;
				break;
			}
			else
				nu[mat[i][j]] = true;
		}
		if (!flag)
			break;
	}// for int i

	if (!flag)
		return;

	for (int col = 1; col < maxn; col++)
	{
		memset(nu, false, sizeof(nu));
		for (int row = 1; row < maxn; row++)
		{
			if (mat[row][col] > 9 || mat[row][col] < 1)
			{
				flag = false;
				break;
			}
			if (true == nu[mat[row][col]])
			{
				flag = false;
				break;
			}
			else
				nu[mat[row][col]] = true;
		}
		if (!flag)
			break;
	}//for int col
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> casenum;
	while (casenum--)
	{
		flag = true;
		for (int i = 1; i < maxn; i++)
		{
			for (int j = 1; j < maxn; j++)
				cin >> mat[i][j];
		}

		check();
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}// while casenum--
	return 0;
}