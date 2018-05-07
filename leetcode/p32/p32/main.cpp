#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s)
	{
		int len = s.size();
		int *dp = new int[len];
		dp[0] = 0;
		for (int i = 1; i < len; i++)
		{
			if ('(' == s[i])
				dp[i] = 0;
			else
			{
				if ('(' == s[i - 1])
					dp[i] = (i - 1 > 0 ? dp[i - 2] + 2 : 2);
				else if (i - dp[i - 1] - 1 >= 0 && '(' == s[i - dp[i - 1] - 1])
					dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
				else
					dp[i] = 0;
			}
		}

		int res = 0;
		for (int i = 0; i < len; i++)
			res = max(res, dp[i]);
		return res;
	}// int long
};

int main()
{
	string s = "))))((()((";
	Solution sol;
	sol.longestValidParentheses(s);
	return 0;
}