#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;
char alpha_rev[] = "A   3  HIL JM O   2TUVWXY5";
char dig_rev[] = "1SE Z  8 ";

bool work_palin(string str)
{
	bool flag = true;
	for (int i = 0; i < str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - i - 1])
		{
			flag = false;
			break;
		}
	}
	return flag;
}

bool work_mirr(string str)
{
	bool flag = true;
	string mirr = "";
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (isalpha(str[i]))
		{
			if (' ' != alpha_rev[str[i] - 'A'])
				mirr += alpha_rev[str[i] - 'A'];
			else
			{
				flag = false;
				break;
			}
		}
		else
		{
			if (' ' != dig_rev[str[i] - '1'])
				mirr += dig_rev[str[i] - '1'];
			else
			{
				flag = false;
				break;
			}
		}
	}//for
	if (!flag)
		return false;
	if (str == mirr)
		return true;
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string str;
	while (getline(cin, str))
	{
		bool is_palin = work_palin(str);
		bool is_mirr = work_mirr(str);

		string res;
		if (!is_palin && !is_mirr)
			res = " -- is not a palindrome.";
		else if (is_palin && !is_mirr)
			res = " -- is a regular palindrome.";
		else if(!is_palin && is_mirr)
			res = " -- is a mirrored string.";
		else
			res = " -- is a mirrored palindrome.";
		cout << str + res << endl<<endl;
	}//while
	return 0;
}