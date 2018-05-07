#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 20 + 10;
int su[maxn];
int nu;

long long work(int st, int ed)
{
	long long res = 1;
	for (int i = st; i <= ed; i++)
		res *= su[i];

	return res;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kase = 0;
	while (cin >> nu && nu)
	{
		for (int i = 0; i < nu; i++)
			cin >> su[i];
		long long ma_tm = 0;

		
		for (int st = 0; st < nu; st++)
		{
			for (int ed = st; ed < nu; ed++)
			{
				long long temp = work(st, ed);
				if (temp > ma_tm)
					ma_tm = temp;
			}
		}
		cout << "Case #" << ++kase << ": The maximum product is " << ma_tm << "." << endl << endl;
	}//while
	return 0;
}