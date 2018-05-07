#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		vector<vector<int> > vvi;
		set<vector<int> > svi;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (i && nums[i] == nums[i - 1])
				continue;
			for (int j = i + 1; j < nums.size(); j++)
			{
				int t = -nums[i] - nums[j];
				int ind = lower_bound(nums.begin(), nums.end(), t) - nums.begin();
				if (ind  == nums.size())
					continue;
				while (ind < nums.size() - 1 && (nums[ind + 1] == nums[ind]))
					ind++;

				if (ind <= j)
					continue;

				if (t == nums[ind])
				{
					vector<int> vi = { nums[i], nums[j], nums[ind] };
					sort(vi.begin(), vi.end());
					svi.insert(vi);
				}

			}//for int j
		}//for int i

		for (set<vector<int> >::iterator it = svi.begin(); it != svi.end(); it++)
			vvi.push_back(*it);

		return vvi;
	}//threeSum
};