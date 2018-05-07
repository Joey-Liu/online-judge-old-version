#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

int n;
char ch;
string s[6], strone, strtwo, secondline;

void read()
{
	for (int i = 0; i <= 5; i++)
		s[i].clear();
	secondline.clear();

	while ((ch = getchar()) != '\n')
		s[0] += ch;
	while ((ch = getchar()) != '\n' && (ch != EOF))
		secondline += ch;

	int fpos1 = 0, spos1 = 0, fpos2, spos2;
	fpos1 = s[0].find('<');
	s[1] = s[0].substr(0, fpos1);
	spos1 = s[0].find('>');
	for (int i = fpos1 + 1; i < spos1; i++)
		s[2] += s[0][i];

	fpos2 = s[0].find('<', spos1);
	for (int i = spos1 + 1; i < fpos2; i++)
		s[3] += s[0][i];
	spos2 = s[0].find('>', fpos2);
	for (int i = fpos2 + 1; i < spos2; i++)
		s[4] += s[0][i];

	for (int i = spos2 + 1; i < s[0].length(); i++)
		s[5] += s[0][i];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		read();
		for (int i = 1; i <= 5; i++)
			cout << s[i];
		cout << endl;
		cout << secondline.substr(0, secondline.length() - 3);
		cout << s[4] << s[3] << s[2] << s[5] << endl;
	}
	return 0;
}

