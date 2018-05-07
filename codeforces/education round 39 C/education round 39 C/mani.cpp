#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

char cur_c;


int main()
{
	string str;
	while (cin >> str)
	{
		int st = -1;
		for (int i = 0; i < str.size(); i++)
		{
			if ('a' == str[i])
			{
				st = i;
				break;
			}
		}
		
		if (st < 0)
			cout << -1 << endl;
		else
		{
			bool flag = false;
			st += 1;
			cur_c = 'b';
			while (st < str.size())
			{
				if (str[st] <= cur_c)
				{
					str[st] = cur_c;
					if ('z' == cur_c)
					{
						flag = true;
						break;
					}
					else
						cur_c++;
				}
				st += 1;
			}
			if (flag)
				cout << str << endl;
			else
				cout << -1 << endl;
		}
	}
}