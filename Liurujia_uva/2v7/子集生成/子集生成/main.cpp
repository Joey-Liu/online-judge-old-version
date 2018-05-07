#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void print_subset(int n, int* A, int cur)
{
	for (int i = 0; i < cur; i++)
		printf("%d ", A[i]);
	printf("\n");

	int s = cur ? A[cur - 1] + 1 : 0;
	for (int i = s; i < n; i++)
	{
		A[cur] = i;
		print_subset(n, A, cur + 1);
	}
}

void bit_print_subset(int n, int A[], int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
			if (A[i])
				cout << i << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			A[cur] = i;
			bit_print_subset(n, A, cur + 1);
		}
	}
}

void bin_print_subset(int n, int state)
{
	for (int i = 0; i < n; i++)
	{
		if (state & (1 << i))
			printf("%d ", i);
	}
	printf("\n");
}


void b_print(int n)
{
	for (int i = 0; i < (1 << n); i++)
		bin_print_subset(n, i);
}

int main()
{
	int *A = new int[8];
	//bit_print_subset(rf8, A, 0);
	b_print(8);
	system("pause");
	return 0;
}