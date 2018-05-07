#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	map<int, int> dict;
	for (int i = 0; i < nums.size(); i++) {
		dict.insert(pair<int, int>(nums[i], i));
	}
	
	map<int, int>::iterator iter;
	for (int i = 0; i < nums.size(); i++) {
		iter = dict.find(target - nums[i]);
		if (iter != dict.end() && iter->second != i)
		{
			res.push_back(i);
			res.push_back(dict[target - nums[i]]);
			break;
		}
	}

	return res;
}


int main()
{
	vector<int> a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(4);

	vector<int> b = twoSum(a, 6);
	for (int i = 0; i < b.size(); i++)
		cout << b[i] << endl;
	system("pause");
}