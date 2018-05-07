#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 15;

int casenum;
int len;
//string str;
char str[maxn];

int cmp(const void* a, const void* b)
{
	char* _a = (char*)a;
	char* _b = (char*)b;
	if (tolower(*_a) == tolower(*_b))
		return *_a <= *_b;				// <= 
	else
		return tolower(*_a) < tolower(*_b);
}

bool scmp(char a, char b)
{
	if (tolower(a) == tolower(b))
	{
		return a < b;
	}
	else
	{
		return tolower(a) < tolower(b);
	}
}

bool solve()
{
	int i = len - 1;
	while (i > 0 && !scmp(str[i - 1], str[i]))
		i--;
	if (0 == i)
		return false;

	int j = len - 1;
	while (cmp(str + j, str + i - 1) && j > i - 1)
		j--;

	swap(str[i - 1], str[j]);
	sort(str + i, str + len, scmp);
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> casenum;
	while (casenum--)
	{
		cin >> str;
		len = strlen(str);
		//qsort(str, len, sizeof(char), cmp);
		sort(str, str + len, scmp);
		cout << str << endl;

		while (solve())
			cout << str << endl;

	}
	return 0;
}