#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <string.h>

using namespace std;
const char str[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
const int maxn = 100;

int indexOf(char c)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
			return i;
	}

	return -1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	char ch;
	string s;
	while (getline(cin, s))
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (' ' == s[i])
				ch = ' ';
			else
			{
				int index = indexOf(s[i]);
				ch = str[index - 1];
			}
			printf("%c", ch);
		}
		printf("\n");
	}
}