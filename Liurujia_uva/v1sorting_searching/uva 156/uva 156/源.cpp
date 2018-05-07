#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 20;
struct word
{
	char ori[100];
	char sortori[100];
	bool flag;

	word()
	{
		this->flag = false;
	}
};

char wtemp[100];
word raa[maxn], res[maxn];
int wordnum = 0;
string str;

int cmp(const void * _a, const void * _b)
{
	word *a = (word *)_a;
	word *b = (word *)_b;

	return strcmp(a->ori, b->ori);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (getline(cin, str))
	{
		if ('#' == str[0])
			break;
		stringstream ss(str);

		while (ss >> wtemp)
		{
			strcpy(raa[wordnum++].ori, wtemp);
			strcpy(raa[wordnum - 1].sortori, raa[wordnum - 1].ori);
			int len = strlen(raa[wordnum - 1].sortori);
			for (int i = 0; i < len; i++)
				raa[wordnum - 1].sortori[i] = tolower(raa[wordnum - 1].sortori[i]);

			sort(raa[wordnum - 1].sortori, raa[wordnum - 1].sortori + len);
			for (int i = 0; i < wordnum - 1; i++)
			{
				if (0 == strcmp(raa[i].sortori, raa[wordnum - 1].sortori))
				{
					raa[i].flag = true;
					raa[wordnum - 1].flag = true;
				}
			}//for int i

		}
	}//while getline

	int index = 0;
	for (int i = 0; i < wordnum; i++)
	{
		if (!raa[i].flag)
			res[index++] = raa[i];
	}
	
	qsort(res, index, sizeof(word), cmp);
	for (int i = 0; i < index; i++)
		cout << res[i].ori << endl;

	return 0;
}