#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stack>

using namespace std;
const int maxn = 10000 + 10;
stack<char> st;
char ch;
char str[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N;
	scanf("%d", &N);
	getchar();
	while (N--)
	{
		int len = 0;
		while ((ch = getchar()) != EOF && ch != '\n')
			str[len++] = ch;
		str[len] = '\0';

		bool flag = true;
		while (!st.empty())
			st.pop();
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '(' || str[i] == '[')
				st.push(str[i]);
			else
			{
				if (str[i] == ')')
				{
					if (!st.empty() && st.top() == '(')
						st.pop();
					else
					{
						flag = false;
						break;
					}
				}
				if (str[i] == ']')
				{
					if (!st.empty() && st.top() == '[')
						st.pop();
					else
					{
						flag = false;
						break;
					}
				}
			}//else
		}
		if (!st.empty())
			flag = false;
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}