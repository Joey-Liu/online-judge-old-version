#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <memory.h>

using namespace std;

const int maxn = 100000 + 100;
int step, mod;
bool num[maxn];

bool solve()
{
	memset(num, false, sizeof(num));
	
	int seed = 0;
	for (int i = 0; i < mod; i++)
	{
		num[seed] = true;
		seed = (seed + step) % mod;
	}

	for (int i = 0; i < mod; i++)
	{
		if (!num[i])
			return false;
	}

	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> step >> mod)
	{
		cout.setf(ios::right);
		cout.width(10);
		cout << step;
		
		cout.setf(ios::right);
		cout.width(10);
		cout << mod;
		cout << "    ";

		cout << (solve() ? "Good Choice" : "Bad Choice") << endl << endl;

	}
	return 0;
}