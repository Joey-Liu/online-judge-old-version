#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>

using namespace std;

const int maxn = 100 + 10 ;

int nu, kinds;
map<string, int> mar;
string courses[maxn][maxn], cou;
int cnum[maxn], cpass[maxn];

bool getDigree()
{
	int cnt = 0;
	for (int i = 0; i < kinds; i++)
	{
		cnt = 0;
		for (int j = 0; j < cnum[i]; j++)
		{
			if (mar[courses[i][j]] == 1)
				cnt++;
		}

		if (cnt < cpass[i])
			return false;
	}

	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin>>nu && nu != 0)
	{
		cin >> kinds;
		mar.clear();

		for (int i = 0; i < nu; i++)
		{
			cin >> cou;
			mar[cou]++;
		}

		for (int i = 0; i < kinds; i++)
		{
			cin >> cnum[i] >> cpass[i];
			for (int j = 0; j < cnum[i]; j++)
			{
				cin >> courses[i][j];
			}
		}//for int i

		if (getDigree())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}//while

	return 0;
}