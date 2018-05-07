#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	cin >> kasenum;
	getchar();
	while (kasenum--)
	{
		string str;
		
		getline(cin, str);
		stack<char> sta;

		bool flag = true;
		for (int i = 0; i < str.size(); i++)
		{
			if ('(' == str[i] || '[' == str[i])
				sta.push(str[i]);
			else if (')' == str[i])
			{
				if (!sta.empty() && '(' == sta.top())
					sta.pop();
				else
					flag = false;
			}
			else if (']' == str[i])
			{
				if (!sta.empty() && '[' == sta.top())
					sta.pop();
				else
					flag = false;
			}
			if (!flag)
				break;
		}
		if (!sta.empty())
			flag = false;
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}//while
	return 0;
}