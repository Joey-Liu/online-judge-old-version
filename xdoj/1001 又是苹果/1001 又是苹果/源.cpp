#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 1000000 + 10;

int col[maxn], row[maxn];
void change_col(int i, int j)
{
	int tmp = col[i];
	col[i] = col[j];
	col[j] = tmp;
}

void change_row(int i, int j)
{
	int tmp = row[i];
	row[i] = row[j];
	row[j] = tmp;
}
string str[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, m, q, a, b, c, casenum = 1;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
			row[i] = i;
		for (int j = 1; j <= m; j++)
			col[j] = j;
		for (int i = 1; i <= n; i++)
			cin >> str[i];
		cin >> q;
		cout << "Case #" << casenum++ << ":" << endl;
		while (q--)
		{
			cin >> a >> b >> c;
			if (1 == a)
			{
				if ('T' != str[row[b]][col[c] - 1] && 'i' != str[row[b]][col[c] - 1])
					cout << "Empty" << endl;
				else if ('T' == str[row[b]][col[c] - 1])
					cout << "Tree" << endl;
				else
					cout << "Phone" << endl;
			}
			else if (2 == a)
				change_row(b, c);
			else
				change_col(b, c);
		}
	}//cin>>
	return 0;
}