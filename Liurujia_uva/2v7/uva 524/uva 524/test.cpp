#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int N;

bool is_prime(int n)
{
	if (n == 1)
		return false;
	if (2 == n)
		return true;

	bool flag = false;
	for (int i = 2; i < sqrt(n); i++)
	{
		if (0 == n % i)
		{
			flag = true;
			break;
		}
	}

	return !flag;
}

vector<int> vi;
vector<vector<int> > arr;

void gen_permuation(vector<int> & vi)
{
	if (vi.size() == N)
		arr.push_back(vi);
	else
	{
		for (int i = 1; i <= N; i++)
		{
			bool flag = true;
			for (int j = 0; j < vi.size(); j++)
			{
				if (vi[j] == i)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				vi.push_back(i);
				gen_permuation(vi);
				vi.pop_back();
			}
		}
	}
}

int main()
{
	while (cin >> N && N)
	{
		arr.clear();
		vector<int> vi;
		gen_permuation(vi);

		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = 0; j < arr[i].size(); j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}