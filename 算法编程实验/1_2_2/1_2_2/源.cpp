#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	while (cin >> casenum)
	{
		long long a = 0, b = 0;
		for (int i = 0; i < casenum; i++)
		{
			cin >> b;
			a ^= b;
		}
		cout << (0 != a ? "Yes" : "No") << endl;
	}//while
	return 0;
}