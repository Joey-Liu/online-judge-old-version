#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int casenum;
int num;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> casenum;
	while (casenum--)
	{
		cin >> num;
		if (num <= 540)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}