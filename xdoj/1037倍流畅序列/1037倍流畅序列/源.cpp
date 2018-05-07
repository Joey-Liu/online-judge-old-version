#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;
int casenum;
string str;

bool check()
{
	if (1 == str.size() % 2)
		return false;

	for (int i = 0; i < str.size() / 2; i++)
	{
		if (str[i] == str[str.size() - i - 1])
			return false;
	}
	return true;
}

void work()
{
	int pos = str.size() / 2;
	if (1 == str.size() % 2)
		pos++;

	int op;			//op = pos - 1 at first
	int st;
	bool hasFind = false;

	for (; pos < str.size(); pos++)
	{
		st = pos;
		op = st - 1;
		while (str[st] != str[op])
		{
			st++;
			op--;
			if (st >= str.size())
			{
				hasFind = true;
				break;
			}
		}
		if (hasFind)
			break;
	}//for

	string ns = "";
	int need = str.size() - (str.size() - pos) * 2;
	need--;
	for (; need >= 0; need--)
	{
		if ('0' == str[need])
			ns += '1';
		else
			ns += '0';
	}
	cout << str << ns << endl;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> casenum;
	while (casenum--)
	{
		cin >> str;
		if (check())
		{
			cout << str << endl;
			continue;
		}

		//从中间开始贪心
		work();
	}//while casaenum--
}