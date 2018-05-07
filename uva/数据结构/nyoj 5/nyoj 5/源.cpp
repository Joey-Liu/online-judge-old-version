#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
const int maxn = 1000 + 100;
char context[maxn], pattern[maxn];
int mynext[maxn];

void GetNextval(char* p, int next[])
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀    
		if (k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			//较之前next数组求法，改动在下面4行  
			if (p[j] != p[k])
				next[j] = k;   //之前只有这一行  
			else
				//因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
				next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
}



int KmpSearch(char* s, char* p, int next[])
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int casenum;
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%s", pattern);
		scanf("%s", context);
		memset(mynext, 0, sizeof(mynext));
		
		GetNextval(pattern, mynext);
		int cnt = 0, index = 0;
		char *ad = context;
		while (true)
		{
			index = KmpSearch(ad, pattern, mynext);
			if (index == -1)
				break;
			cnt++;
			ad = ad + index + 1;
		}
		printf("%d\n", cnt);
	}
	return 0;
}