#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int maxn = 50 + 60;
int L, kasenum, carr[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> kasenum;
	while (kasenum--)
	{
		cin >> L;
		for (int i = 0; i < L; i++)
			cin >> carr[i];

		int res = 0;
		for (int i = 0; i < L; i++)
		{
			for (int j = i + 1; j < L; j++)
			{
				if (carr[i] > carr[j])
				{
					swap(carr[i], carr[j]);
					res++;
				}
			}
		}
		cout << "Optimal train swapping takes " << res << " swaps." << endl;
	}//while
	return 0;
}