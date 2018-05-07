#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sstream>
#include <map>

using namespace std;
const int maxn = 6000;
char line[maxn];
char words[maxn][300];
char temp[300];
int wordsNum = 0;
map<string, int> wordsMap;

int cmp(const void * a, const void * b)
{
	char * c = (char *)a;
	char * d = (char *)b;
	return strcmp(c, d);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (gets(line))
	{
		for (int i = 0; i < strlen(line); i++)
		{
			if (isalpha(line[i]))
				line[i] = tolower(line[i]);
			else
				line[i] = ' ';
		}

		stringstream ss(line);
		while (ss >> temp)
		{
			string str(temp);
			if (!wordsMap.count(str))
			{
				wordsMap[str] = 1;
				strcpy(words[wordsNum++], temp);
			}
		}
		//char * p = line;
		/*
		while (sscanf(p, "%s", temp) > 0)
		{
			string str = string(temp);
			p += str.length();

			if (!wordsMap.count(str))
				wordsMap[str] = 1;
			strcpy(words[wordsNum++], temp);
		}
		*/
	}//while gets

	qsort(words, wordsNum, sizeof(words[0]), cmp);
	for (int i = 0; i < wordsNum; i++)
		printf("%s\n", words[i]);

	return 0;
}