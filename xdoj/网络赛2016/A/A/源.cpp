#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int a, b, c, d;
char ch;
string str;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> str)
	{
		stringstream ss(str);
		ss >> a;
		ss >> ch;
		ss >> b;
		ss >> ch;

		cin >> str;
		ss.clear();
		ss.str(str);
		ss >> c;
		ss >> ch;
		ss >> d;

		int x = a + c;
		int y = b + d;
		printf("%d%+di\n", x, y);
	}

	return 0;
}