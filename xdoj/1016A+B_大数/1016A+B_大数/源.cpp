#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;

const int maxn = 50;
int a[maxn], b[maxn],c[maxn];
string A, B;

void add()
{
	c[0] = a[0] > b[0] ? a[0] : b[0];
	for (int i = 1; i <= c[0]; i++)
	{
		c[i] = a[i] + b[i];
		if (c[i] >= 10)
		{
			c[i] -= 10;
			c[i + 1]++;
		}
	}
	while (c[c[0] + 1] != 0)
		c[0]++;
}

int main()
{
	while (cin >> A >> B)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		a[0] = A.size();
		b[0] = B.size();

		int ind = 1;
		for (int i = A.size() - 1; i >= 0; i--)
			a[ind++] = A[i] - '0';

		ind = 1;
		for (int i = B.size() - 1; i >= 0; i--)
			b[ind++] = B[i] - '0';
		add();
		for (int i = 1; i <= c[0]; i++)
			cout << c[i];
		cout << endl;
	}
}