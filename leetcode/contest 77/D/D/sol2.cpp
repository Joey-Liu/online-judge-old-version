#include <vector>
#include <set>

using namespace std;

class Solution
{
public:

	bool findSum(int ind, int nu, int tar, const vector<int> & A)
	{
		if (!nu)
			return !tar;

		for (int i = ind; i <= A.size() - nu; i++)
		{
			if (A[i] <= tar && findSum(i + 1, nu - 1, tar - A[i], A))
				return true;
		}
		return false;
	}

	bool splitArraySameAverage(vector<int>& A)
	{
		int S = 0, N = A.size();
		for (int i = 0; i < A.size(); i++)
			S += A[i];
		
		for (int i = 1; i <= A.size() / 2; i++)
		{
			if (0 == (S * i) % N && 0 == (S * (N - i)) % N)
			{
				int Sa = S * i / N;
				if (findSum(0, i, Sa, A))
					return true;
			}
		}//for int i
		return false;
	}//bool 
};

int main()
{
	vector<int> vi = { 2, 12, 18, 16, 19, 3 };
	Solution sol;
	sol.splitArraySameAverage(vi);
}