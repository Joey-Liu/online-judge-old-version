#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;

string str[2];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> str[0] >> str[1])
	{
		int i = 0, j = 0, flag = 0;
		while (true)
		{
			while (j < str[1].size() && str[0][i] != str[1][j])
				j++;
			if (i < str[0].size() && j >= str[1].size())
				break;
			i++;
			j++;
			if (i >= str[0].size())
			{
				flag = 1;
				break;
			}
		}//while true
		string res = (1 == flag ? "Yes" : "No");
		cout << res << endl;
	}//while
	return 0;
}