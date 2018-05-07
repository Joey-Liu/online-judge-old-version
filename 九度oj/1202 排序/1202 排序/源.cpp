#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 100 + 20;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int size = 0;
	int nu[maxn];
	while (cin >> size)
	{
		for (int i = 0; i < size; i++)
			cin >> nu[i];
		sort(nu, nu + size);

		for (int i = 0; i < size; i++)
		{
			cout << nu[i];
			if (i != size - 1)
				cout << " ";
		}
	}

	return 0;
}