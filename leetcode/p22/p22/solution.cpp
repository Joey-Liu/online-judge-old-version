#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(string str, int n, int ls, int rs, vector<string> & vvi)
{
	if (ls + rs == n * 2)
	{
		vvi.push_back(str);
		return;
	}

	if (ls < n)
		dfs(str + "(", n, ls + 1, rs, vvi);
	if (ls > rs)
		dfs(str + ")", n, ls, rs + 1, vvi);
}

class Solution 
{
public:
	vector<string> generateParenthesis(int n) 
	{
		vector<string> vs;
		vector<vector<int> > vvi;
		vector<int> vi;

		dfs("", n, 0, 0, vs);
		return vs;
	}
};