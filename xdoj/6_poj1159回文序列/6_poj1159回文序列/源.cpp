#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 5000 + 5;
short dp[maxn][maxn];
string str;
int length;

int main()
{
	while (cin >> length)
	{
		cin >> str;
		memset(dp, 0, sizeof(dp));

		for (int len = 2; len <= str.size(); len++)
		{
			for (int lp = 0; lp + len - 1 < str.size(); lp++)
			{
				int rp = lp + len - 1;
				if (str[lp] == str[rp])
					dp[lp][rp] = dp[lp + 1][rp - 1];
				else
					dp[lp][rp] = min(dp[lp][rp - 1] + 1, dp[lp + 1][rp] + 1);
			}
		}// for int len

		cout << dp[0][str.size() - 1] << endl;
	}//while
	return 0;
}