#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 50 + 10;

char str[maxn];
int len;

bool solve()
{
	len = strlen(str);
	int i = len - 1;
	while (i > 0 && str[i - 1] >= str[i])
		i--;
	if (0 == i)
		return false;//ÎÞºó¼Ì

	int j = len - 1;
	while (str[j] <= str[i - 1] && j > i - 1)
		j--;
	
	swap(str[i - 1], str[j]);
	sort(str + i, str + len);
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> str;
	while (0 != strcmp(str, "#"))
	{
		if (solve())
			cout << str << endl;
		else
			cout << "No Successor" << endl;
		cin >> str;
	}
	return 0;
}