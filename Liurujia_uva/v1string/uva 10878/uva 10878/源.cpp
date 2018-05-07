#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

const string endline = "___________";
string str;
bool flag = false;
int first, second, result;

void work()
{
	first = 0; second = 0;
	int radio = 1;
	for (int i = 4; i >= 2; i--)
	{
		if ('o' == str[i])
		{
			first += radio;
		}
		radio *= 2;
	}

	radio = 1;
	for (int i = 9; i >= 5; i--)
	{
		if (6 == i)
			continue;
		if ('o' == str[i])
			second += radio;
		radio *= 2;
	}

	result = (first << 4) + second;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (true)
	{
		getline(cin, str);
		if (str == endline)
		{
			if (flag)
				break;
			else
				continue;
		}
		flag = true;
		work();
		cout << (char)result;
	}//while
	return 0;
}