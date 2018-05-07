#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const int maxn = 4;
int ind = 0;
void print_sub(int n, int A[], int cur)
{
	for (int i = 0; i < cur; i++)
		cout << A[i] << " ";
	cout << endl;
	ind++;

	int st = 0;
	if (!cur)
		st = 0;
	else
		st = A[cur - 1] + 1;
	for (int i = st; i < n; i++)
	{
		A[cur] = i;
		print_sub(n, A, cur + 1);
	}
}

void print_subset_2(int n, int B[], int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (B[i])
				cout << i << " ";
		}
		cout << endl;
		return;
	}

	B[cur] = 1;
	print_subset_2(n, B, cur + 1);
	B[cur] = 0;
	print_subset_2(n, B, cur + 1);
}

void print_subset_3(int n, int s)
{
	for (int i = 0; i < n; i++)
	{
		if (s & (1 << i))
			cout << i << " ";
	}
	cout << endl;
}

int main()
{
	int A[maxn];
	for (int i = 0; i < maxn; i++)
		A[i] = i;
	print_sub(maxn, A, 0);
	//for (int i = 0; i < (1 << maxn); i++)
	//	print_subset_3(maxn, i);

	cout << ind << endl;
	system("pause");
	return 0;
}