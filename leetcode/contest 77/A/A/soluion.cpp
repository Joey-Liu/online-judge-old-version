#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
	vector<int> numberOfLines(vector<int>& widths, string S) 
	{
		int ind = 0;
		int row = 0, cur = 0;
		while (ind < S.size())
		{
			int t_wid = widths[S[ind] - 'a'];
			if (cur + t_wid > 100)
			{
				row++;
				cur = t_wid;
			}
			else
				cur += t_wid;
			ind++;
		}
		vector<int> vi;
		vi.push_back(row + 1);
		vi.push_back(cur);
		return vi;
	}
};