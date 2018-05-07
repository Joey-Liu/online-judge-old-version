#include <iostream>
#include <vector>

using namespace std;


vector<int> subset(const vector<int> & A, int state)
{
	vector<int> vi;
	for (int i = 0; i < A.size(); i++)
	{
		if ((1 << i) & state)
			vi.push_back(A[i]);
	}
	return vi;
}

class Solution 
{
public:
	bool splitArraySameAverage(vector<int>& A) 
	{
		double avg = 0.0;
		for (int i = 0; i < A.size(); i++)
			avg += A[i];
		avg /= A.size();
		
		for (int i = 1; i < (1 << A.size()); i++)
		{
			vector<int> vi = subset(A, i);
			if (vi.size() == A.size())
				continue;
			double t = 0.0;
			for (int i = 0; i < vi.size(); i++)
				t += vi[i];
			t /= vi.size();
			if (t == avg)
				return true;
		}
		return false;
	}
};

int main()
{
	Solution sol;
	//vector<int> vi = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> vi = { 33, 86, 88, 78, 21, 76, 19, 20, 88, 76, 10, 25, 37, 97, 58, 89, 65, 59, 98, 57, 50, 30, 58, 5, 61, 72, 23, 6 };
	sol.splitArraySameAverage(vi);
}