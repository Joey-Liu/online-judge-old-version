#include <iostream>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;

const int maxn = 100;

int A, B;
bool tab[maxn][maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> A >> B;
	memset(tab, 0, sizeof(tab));
	
	for (int i = 0; i < 25; i++)
		memset(tab[i], 1, sizeof(tab[i]));

	int wn = 1, bn = 1;
	bool flag = false;
	if (wn == A)
		flag = true;
	for (int i = 0; i <= 24; i += 2)
	{
		if (flag)
			break;
		for (int j = 0; j < 99; j += 2)
		{
			tab[i][j] = 0;
			wn += 1;
			if (wn == A)
			{
				flag = true;
				break;
			}
		}
	}

	flag = false;
	if (bn == B)
		flag = true;
	for (int i = 26; i <= 48; i += 2)
	{
		if (flag)
			break;
		for (int j = 0; j < 100; j += 2)
		{
			tab[i][j] = 1;
			bn++;
			if (bn == B)
			{
				flag = true;
				break;
			}
		}
	}

	cout << 100 << " " << 100 << "\n";
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (tab[i][j])
				cout << "#";
			else
				cout << ".";
		}
		cout << "\n";
	}
	return 0;
}