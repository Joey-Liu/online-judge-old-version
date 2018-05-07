#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
		vector<vector<int> > vvi;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		if (n < 4)
			return vvi;

		for (int i = 0; i < nums.size() - 3; i++)
		{
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
				break;
			if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
				continue;
			
			for (int j = i + 1; j < nums.size() - 2; j++)
			{
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
					break;
				if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
					continue;

				int tmp = nums[i] + nums[j];
				int lp = j + 1, rp = n - 1;
				while (lp < rp)
				{
					if (nums[lp] + nums[rp] + tmp > target)
						rp--;
					else if (nums[lp] + nums[rp] + tmp < target)
						lp++;
					else
					{
						vector<int> vi;
						vi.push_back(nums[i]); vi.push_back(nums[j]);
						vi.push_back(nums[lp]); vi.push_back(nums[rp]);
						vvi.push_back(vi);
						while (lp < rp && nums[lp] == nums[lp + 1])
							lp++;
						lp++;
						while (rp > lp && nums[rp] == nums[rp - 1])
							rp--;
						rp--;
					}
				}
				while (j < n && nums[j] == nums[j + 1])
					j++;
			}//for int j
			while (i < n && nums[i] == nums[i + 1])
				i++;
		}//for int i
		return vvi;
	}
};