#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

void print_permutation(int A[], int cur, int max_length)
{
	if (cur == max_length)
	{
		for (int i = 0; i < cur; i++)
			cout << " " << A[i];
		cout << endl;
		return;
	}

	for (int i = 0; i < max_length; i++)
	{
		bool flag = true;
		for (int j = 0; j < cur; j++)
		{
			if (A[j] == i)
				flag = false;
		}
		if (flag)
		{
			A[cur] = i;
			print_permutation(A, cur + 1, max_length);
		}
	}
}

void print_pertumation_2(int A[], int P[], int cur, int max_length)
{
	if (cur == max_length)
	{
		for (int i = 0; i < max_length;i++)
			cout << " " << A[i];
		cout << endl;
		return ;
	}

	for (int i = 0; i < max_length; i++)
	{
		if (!i || P[i] != P[i - 1])
		{
			int c1 = 0, c2 = 0;
			for (int j = 0; j < cur; j++)
				if (A[j] == P[i])
					c1++;

			for (int j = 0; j < max_length; j++)
				if (P[j] == P[i])
					c2++;
			
			if (c1 < c2)
			{
				A[cur] = P[i];
				print_pertumation_2(A, P, cur + 1, max_length);
			}
		}// if i
	}//for int i
}

const int maxn = 5;

int cmp(const void *a, const void *b)
{
	return (*((int *)a) - *((int *)b));
}


int main()
{
	int A[maxn];
	memset(A, -1, sizeof(A));
	//print_permutation(A, 0, maxn);
	int P[] = { 1, 1, 1, 1, 4 };
	print_pertumation_2(A, P, 0, maxn);
	
	int n = 7;
	int B[] = { 3, 5, 1, 6, 8, 5 ,3 };
	qsort(B, n, sizeof(int), cmp);

	do
	{
		for (int i = 0; i < n; i++)
			cout << " " << B[i];
		cout << endl;
	} while (next_permutation(B, B + n));
	system("pause");
	return 0;
}