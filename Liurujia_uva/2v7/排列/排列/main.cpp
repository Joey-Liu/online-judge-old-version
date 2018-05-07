#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 5;

int num[maxn];

void print_permutation(int cur)
{
	if (cur == maxn)
	{
		for (int i = 0; i < maxn; i++)
			cout << num[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < maxn; i++)
		{
			bool flag = true;
			for (int j = 0; j < cur; j++)
			{
				if (num[j] == i)
					flag = false;
			}
			if (flag)
			{
				num[cur] = i;
				print_permutation(cur + 1);
			}
		}//for
	}
}

void print_pertamution(int *A, int n, int cur, int *p)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (i && p[i] == p[i - 1])
				continue;
			int c1 = 0, c2 = 0;
			for (int j = 0; j < n; j++)
				if (p[j] == p[i])
					c1++;

			for (int j = 0; j < cur; j++)
				if (A[j] == p[i])
					c2++;

			if (c2 < c1)
			{
				A[cur] = p[i];
				print_pertamution(A, n, cur + 1, p);
			}
		}
	}
}

int main()
{
	//print_permutation(0);
	//int p[] = { 3, 5,1,4,7,2 };
	int p[] = { 2, 2, 1,3,3,1 };
	int size = sizeof(p) / sizeof(int);
	sort(p, p + size);
	/*int *A = new int[size];
	print_pertamution(A, size, 0, p);*/

	do
	{
		for (int i = 0; i < size; i++)
			cout << p[i] << " ";
		cout << endl;
	} while (next_permutation(p, p + size));
	system("pause");
	return 0;
}