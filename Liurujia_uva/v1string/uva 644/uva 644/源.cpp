#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;
const int maxn = 100;
string str[maxn], line;

int cnt = 0, kase = 0;

bool work()
{
	int k = 0;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			if (i == j || str[i].length() > str[j].length())
				continue;
			for (k = 0; k < str[i].length(); k++)
			{
				if (str[i][k] != str[j][k])
					break;
			}
 			if (k == str[i].length())
				return false;
		}
	}//for int i
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	bool flag = false;
	cnt = 0;
	while (cin >> line)
	{
		if (line == "9")
		{
			flag = work();
			cout << "Set " << ++kase;
			if (flag)
				cout << " is immediately decodable" << endl;
			else
				cout << " is not immediately decodable" << endl;
			cnt = 0;
		}
		else
			str[cnt++] = line;
	}//while cin>>line
	return 0;

}