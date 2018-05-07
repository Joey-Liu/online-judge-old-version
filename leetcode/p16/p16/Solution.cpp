#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		int ind = 0, dist = 0x3f3f3f3f, ans = 0;
		sort(nums.begin(), nums.end());
		while (ind < nums.size())
		{
			int lp = ind + 1;
			int rp = nums.size() - 1;
			int t = target - nums[ind];

			while (lp < rp)
			{
				int sum = nums[lp] + nums[rp];
				int di = t - sum;
				if (di < 0)
					di = -di;
				if (di < dist)
				{
					dist = di;
					ans = sum + nums[ind];
				}


				if (sum > t)
					rp--;
				else if (sum < t)
					lp++;
				else
					return target;

			}//while lp rp
			ind++;
		}//while ind
		return ans;
	}
};

int main()
{
	vector<int> te = { 1 ,1, 1, 0 };
	Solution sol;
	sol.threeSumClosest(te, 100);
	return 0;
}