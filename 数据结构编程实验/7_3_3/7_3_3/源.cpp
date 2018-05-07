#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn_word = 100 + 20;
const int maxn_wsize = 10;

char word[maxn_word][maxn_wsize];
char sorted[maxn_word][maxn_wsize];

int cmp_string(const void* _a,const void* _b)
{
	 char* a = (char* )_a;
	 char* b = (char* )_b;
	 return strcmp(a,b);
}

int cmp_char(const void* _a,const void* _b)
{
	char* a = (char* )_a;
	char* b = (char* )_b;
	return (*a -*b);
}

int main()
{
	freopen("word.in.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n = 0;
	for(;;)
	{
		gets(word[n]);
		if(0==strcmp("XXXXXX",word[n]) )
			break;
		n++;
	}

	qsort(word,n,sizeof(word[0]),cmp_string);
	int i =0;
	for(i = 0;i < n;i++)
	{
		strcpy(sorted[i],word[i]);
		qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_char);
	}

	char tmp[50];
	cin>>tmp;
	while(0 != strcmp("XXXXXX",tmp))
	{
		qsort(tmp,strlen(tmp),sizeof(char),cmp_char);///strlen(tmp)!!1
		bool find = false;
		for(int k =0;k < n;k++)
		{
			if(0==strcmp(tmp,sorted[k]))
			{
				find = true;
				printf("%s\n",word[k]);
			}
		}
		if(!find)
			printf("NOT A VALID WORD\n");
		printf("******\n");
		cin>>tmp;
	}
	return 0;
}