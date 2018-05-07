#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int> > vvi;
		sort(nums.begin(), nums.end());

		int ind = 0;
		while (ind < nums.size())
		{
			int lp = ind + 1;
			int rp = nums.size() - 1;
			int t = -nums[ind];

			while (lp < rp)
			{
				int sum = nums[lp] + nums[rp];
				if (sum < t)
					lp++;
				else if (sum > t)
					rp--;
				else
				{
					vector<int> vi(3, 0);
					vi[0] = nums[ind];
					vi[1] = nums[lp];
					vi[2] = nums[rp];
					vvi.push_back(vi);

					while (lp < rp && nums[lp] == nums[lp + 1])
						lp++;
					lp++;
					while (rp > lp && nums[rp] == nums[rp - 1])
						rp--;
					rp--;
				}
			}

			while (ind < nums.size() - 1 && nums[ind] == nums[ind + 1])
				ind++;
			ind++;
		}//while ind < nums size()
		return vvi;
	}
};

int main()
{
	vector<int> test = { -1, 0, 1, 2, -1 ,4 };
	Solution sol;
	sol.threeSum(test);
}