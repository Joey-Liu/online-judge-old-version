#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		int ind = 0, len = 0;
		for (int i = 0; i < strs.size(); i++)
		{
			if (!i)
				len = strs[i].size();
			len = min(len, (int)strs[i].size());
		}//for int i

		for (ind = 0; ind < len; ind++)
		{
			bool flag = true;
			for (int i = 0; i < strs.size(); i++)
			{
				if (strs[i][ind] != strs[0][ind])
				{
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}//for ind
		
		string str = "";
		if(strs.size())
			str = strs[0].substr(0, ind);
		return str;
	}//longestCommon
};