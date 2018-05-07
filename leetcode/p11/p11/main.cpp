#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define MAX(x, y) ((x) > (y) ? (x) :(y))
#define MIN(x, y) ((x) < (y) ? (x) :(y))

class Solution {
public:
	int maxArea(vector<int>& height) 
	{
		int res = -1;
		int lp = 0, rp = height.size() - 1;
		
		while (lp != rp)
		{
			int thei = MIN(height[lp], height[rp]);
			int tmres = thei * (rp - lp);
			res = MAX(tmres, res);

			height[lp] < height[rp] ? lp++ : rp--;
		}
		return res;
	}
};