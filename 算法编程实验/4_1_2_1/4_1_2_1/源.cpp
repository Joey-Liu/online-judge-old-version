#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 20;
char str[maxn];
int len;

void mswap(char* p, char* q)
{
	char t = *p;
	*p = *q;
	*q = t;
}

bool solve()
{
	len = strlen(str);
	int i = len - 1;
	while (i > 0 && str[i - 1] >= str[i])
		i--;

	if (0 == i)
		return false;

	int j = len - 1;
	while (str[j] <= str[i - 1])
		j--;

	mswap(&str[i - 1], &str[j]);
	sort(str + i, str + len);
	return true;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	cin >> casenum;
	while (casenum--)
	{
		cin >> str;
		sort(str, str + strlen(str));
		cout << str << endl;

		while (solve())
			cout << str << endl;
		cout << endl;
	}
	return 0;
}
