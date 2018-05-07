#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 20;
string finStr[maxn], repStr[maxn];
string text;
int ruleNum;

void work()
{
	for (int i = 0; i < ruleNum; i++)
	{
		while (true)
		{
			int res = text.find(finStr[i], 0);
			if (string::npos == res)
				break;
			text.replace(res, finStr[i].length(), repStr[i]);
		}
	}//for i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> ruleNum && ruleNum)
	{
		getchar();
		for (int i = 0; i < ruleNum; i++)
		{
			getline(cin, finStr[i]);
			getline(cin, repStr[i]);
		}
		getline(cin, text);
		work();
		cout << text << endl;
	}//while

	return 0;
}