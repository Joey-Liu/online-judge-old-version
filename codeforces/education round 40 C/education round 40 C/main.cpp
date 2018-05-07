#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 200000 + 20;
int num[maxn], N, row = -1, col = 1;

bool adj(int a, int b)
{
	row = max(row, (a - 1) / col + 1);
	int a_row = (a - 1) / col + 1;
	int a_col = a - (a_row - 1) * col;

	set<int> si;
	if (a_row > 1)
		si.insert(a - col);
	if (a_col < col)
		si.insert(a + 1);
	if (a_row <= row)
		si.insert(a + col);
	if (a_col > 1)
		si.insert(a - 1);

	if (si.count(b))
		return true;
	else
		return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	bool flag = false, ok = true;
	for (int i = 0; i < N - 1; i++)
	{
		if (num[i] == num[i + 1])
		{
			ok = false;
			break;
		}

		if (ok && 1 != abs(num[i] - num[i + 1]))
		{
			if (!flag)
			{
				col = abs(num[i] - num[i + 1]);
				flag = true;
			}
			else
			{
				if (abs(num[i] - num[i + 1]) != col)
				{
					ok = false;
					break;
				}
			}
		}
	}//for int i
	
	if(ok)
	{
		for (int i = 0; i < N - 1; i++)
		{
			if (!adj(num[i], num[i + 1]))
			{
				ok = false;
				break;
			}
		}
	}

	if (!ok)
		cout << "NO" << endl;
	else
	{
		row = max(row, (num[N - 1] - 1) / col + 1);
		cout << "YES" << endl;
		cout << row << " " << col << endl;
	}
	return 0;
}