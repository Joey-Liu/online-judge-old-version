#include <iostream>
#include <string>
#include <vector>

using namespace std;

string alp[] = { "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz" };

void dfs(string digits, int index, string str, vector<string> & vs)
{
	if (index == digits.size())
	{
		if("" != str)
			vs.push_back(str);
		return;
	}

	int nu = digits[index] - '1';
	for (int i = 0; i < alp[nu].size(); i++)
	{
		string tmp = str;
		str += alp[nu][i];
		dfs(digits, index + 1, str, vs);
		str = tmp;
	}
}

class Solution {
public:
	vector<string> letterCombinations(string digits) 
	{
		vector<string> vs;
		string str = "";
		dfs(digits, 0, str, vs);
		return vs;
	}
};