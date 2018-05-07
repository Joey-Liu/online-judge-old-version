#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 200 + 20;
char str[maxn];

int cmp(const void * p1, const void * p2)
{
	char * a = (char *)p1;
	char * b = (char *)p2;

	return *a - *b;
}

int main()
{
	while (cin >> str)
	{
		qsort(str, strlen(str), sizeof(char), cmp);
		cout << str << endl;
	}
}