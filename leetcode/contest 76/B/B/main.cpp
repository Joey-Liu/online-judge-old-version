#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int minSwap(vector<int>& A, vector<int>& B) 
	{
		int len = A.size();
		int *swap = new int[len];
		int *un_swap = new int[len];

		swap[0] = 1;
		un_swap[0] = 0;
		for (int i = 1; i < len; i++)
		{
			swap[i] = 0x3f3f3f3f;
			un_swap[i] = 0x3f3f3f3f;

			if (A[i - 1] < A[i] && B[i - 1] < B[i])
			{
				un_swap[i] = un_swap[i - 1];
				swap[i] = swap[i - 1] + 1;
			}
			if (A[i - 1] < B[i] && B[i - 1] < A[i])
			{
				swap[i] = min(un_swap[i - 1] + 1, swap[i]);
				un_swap[i] = min(swap[i - 1], un_swap[i]);
			}
		}
		return min(swap[len - 1], un_swap[len - 1]);
	}
};