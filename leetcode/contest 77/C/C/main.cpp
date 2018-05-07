#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
	{
		vector<int> rmax, cmax;
		for (int i = 0; i < grid.size(); i++)
		{
			int t = -1;
			for (int j = 0; j < grid[i].size(); j++)
				t = max(grid[i][j], t);
			rmax.push_back(t);
		}

		for (int j = 0; j < grid[0].size(); j++)
		{
			int t = -1;
			for (int i = 0; i < grid.size(); i++)
				t = max(grid[i][j], t);
			cmax.push_back(t);
		}

		int res = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[i].size(); j++)
				res = res + (min(rmax[i], cmax[j]) - grid[i][j]);
		return res;
	}
};

int main()
{
	int grid[][4] = { {3, 0, 8, 4}, {2, 4, 5, 7},{9, 2, 6, 3},{0, 3, 1, 0} };
	vector<vector<int> > g;
	for (int i = 0; i < 4; i++)
	{
		vector<int> vi;
		for (int j = 0; j < 4; j++)
			vi.push_back(grid[i][j]);
		g.push_back(vi);
	}

	Solution sol;
	sol.maxIncreaseKeepingSkyline(g);
}