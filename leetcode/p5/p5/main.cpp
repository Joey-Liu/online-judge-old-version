#include <string>
using namespace std;

const int maxn = 1000 + 10;
#define MAX(x, y) ((x) > (y) ? (x) : (y))

class Solution {
public:
	string longestPalindrome(string s) 
	{
		bool dp[maxn][maxn];
		memset(dp, false, sizeof(dp));
		int len = s.length();

		for (int i = 0; i < len; i++)
			dp[i][i] = true;

		int resLength = 1, st = 0, en = 0;
		for (int i = 0; i < len - 1; i++)
		{
			if (s[i] == s[i + 1])
			{
				dp[i][i + 1] = true;
				resLength = 2;
				st = i;
				en = i + 1;
			}
		}

		
		for (int le = 3; le <= len; le++)
		{
			for (int i = 0; i < len - le + 1; i++)
			{
				int j = i + le - 1;
				dp[i][j] = (s[j] == s[i] && dp[i + 1][j - 1]);
				if (dp[i][j])
				{
					if (le > resLength)
					{
						resLength = le;
						st = i; en = j;
					}
				}
			}
		}

		return s.substr(st, resLength);
	}// longest
};