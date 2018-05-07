#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;
stack<int> ch_stack;
string str;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	cin.get();
	while (kasenum--)
	{
		getline(cin, str);
		while (!ch_stack.empty())
			ch_stack.pop();
		
		bool flag = true;
		for (int i = 0; i < str.size(); i++)
		{
			if ('(' == str[i] || '[' == str[i])
				ch_stack.push(str[i]);
			else
			{
				if (ch_stack.empty())
				{
					flag = false;
					break;
				}

				if (')' == str[i] && '(' == ch_stack.top())
					ch_stack.pop();
				else if (']' == str[i] && '[' == ch_stack.top())
					ch_stack.pop();
				else
				{
					flag = false;
					break;
				}
			}
		}//for int i

		if (!ch_stack.empty())
			flag = false;
		cout <<( flag ? "Yes" : "No") << endl;
	}//while
	return 0;
}