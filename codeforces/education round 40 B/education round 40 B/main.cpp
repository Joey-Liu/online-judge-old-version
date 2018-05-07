#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int N;
string str;

bool work(int len)
{
	bool flag = true;
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[i + len / 2])
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> str;
	int len = N;
	if (len % 2)
		len--;

	int res = 0;
	bool flag = false;
	while (len > 0)
	{
		flag = work(len);
		if (flag)
			break;
		len -= 2;
	}
	if (flag)
		res = len / 2 + N - len + 1;
	else
		res = N;
	cout << res << endl;
	return 0;
}