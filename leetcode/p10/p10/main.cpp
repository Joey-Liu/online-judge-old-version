#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) 
	{
		int slen = s.length();
		int plen = p.length();

		// dp[i][j] s[:i -1] matches p[:j - 1]
		vector<vector<bool> > dp(slen + 1, vector<bool>(plen + 1, false));

		dp[0][0] = true;
		
		for (int i = 2; i <= plen; i++)
			dp[0][i] = (p[i - 1] == '*' && dp[0][i - 2]);

		for (int i = 1; i <= slen; i++)
		{
			for (int j = 1; j <= plen; j++)
			{
				if (p[j - 1] != '*')
					dp[i][j] = (dp[i - 1][j - 1] && ((p[j - 1] == s[i - 1]) || '.' == p[j - 1]));
				else
					dp[i][j] = (j > 1 && dp[i][j - 2]) || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
			}//for int j
		}//for int i
		return dp[slen][plen];
	}//isMatch
};

int main()
{
	Solution so;
	bool res = so.isMatch("aaa", ".a");
	return 0;
}