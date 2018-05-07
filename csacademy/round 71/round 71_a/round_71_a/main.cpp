#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		bool flag = false;
		int ind = 0;
		while (ind < str.size())
		{
			if (!flag && 'B' == str[ind])
			{
				cout << "B";
				ind++;
			}
			else if (!flag && 'A' == str[ind])
			{
				flag = true;
				ind++;
			}
			else if (flag && 'A' == str[ind])
			{
				ind++;
			}
			else if (flag && 'B' == str[ind])
			{
				flag = false;
				cout << "AB";
				ind++;
			}
		}//while
		if (flag)
			cout << "A";
		cout << endl;
	}//while cin
	return 0;
}