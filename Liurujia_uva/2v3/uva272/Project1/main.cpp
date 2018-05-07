#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	char c;
	bool flag = true;
	while ((c = getchar()) != EOF)
	{
		if ('"' == c && flag)
		{
			printf("``");
			flag = false;
		}
		else if ('"' == c && !flag)
		{
			printf("''");
			flag = true;
		}
		else
			printf("%c", c);
	}//while
	return 0;
}