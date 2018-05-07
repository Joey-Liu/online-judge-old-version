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
		//p[k]��ʾǰ׺��p[j]��ʾ��׺    
		if (k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			//��֮ǰnext�����󷨣��Ķ�������4��  
			if (p[j] != p[k])
				next[j] = k;   //֮ǰֻ����һ��  
			else
				//��Ϊ���ܳ���p[j] = p[ next[j ]]�����Ե�����ʱ��Ҫ�����ݹ飬k = next[k] = next[next[k]]  
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