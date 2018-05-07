#include <iostream>
#include <stdio.h>
#define N 9

using namespace std;

int array[N] = { 2, 1, 6, 3, 5, 4, 8, 7, 9 };
int B[N];
int len;

int BiSearch(int num)
{
	int lp = 0;
	int rp = len - 1;
	int mid = (lp + rp) / 2;

	while (lp + 1 < rp)
	{
		if (B[mid] < num)
			lp = mid;
		else if (B[mid] > num)
			rp = mid;
		else
			return mid;
		mid = (lp + rp) / 2;
	}

	if (B[lp] > num)
		return lp;
	else
		return rp;
}

int LIS(int n)
{
	len = 1;
	B[0] = array[0];
	
	int i = 1, pos = 0;
	for (i = 1; i < n; i++)
	{
		if (array[i] > B[len - 1])
			B[len++] = array[i];
		else
		{
			pos = BiSearch(array[i]);
			B[pos] = array[i];
		}
	}
	return len;
}

int main()
{
	cout << "LIS: " << LIS(N) << endl;
	for (int i = 0; i < len; i++)
		cout << "B[" << i << "] " << B[i] << endl;

	system("pause");
	return 0;
}