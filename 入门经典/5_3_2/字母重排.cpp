#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int n;
char word[2000][10],sorted[2000][10];

int cmp_char(const void* _a,const void* _b)
{
	char* a=(char* )_a;
	char* b=(char* )_b;
	return *a-*b;
}

int cmp_string(const void* _a,const void* _b)
{
	char* a=(char* )_a;
	char* b=(char* )_b;
	return strcmp(a,b);
}

int main()
{
	n=0;
	for(;;)
	{
		cin>>word[n];
		if('*'==word[n][0])
		    break;
		cout<<word[n]<<endl;
		n++;
	}
	
	qsort(word,n,sizeof(word[0]),cmp_string);
	for(int i=0;i<n;i++)
	{
		strcpy(sorted[i],word[i]);
		qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_char);
	}

	char s[10];
	while(cin>>s)
	{
		qsort(s,strlen(s),sizeof(char),cmp_char);
		bool found=false;

		for(int i=0;i<n;i++)
			if(0==strcmp(s,sorted[i]))
			{
				found=true;
				cout<<word[i]<<" ";
			}

		if(false==found)
			cout<<":(";
		cout<<endl;
	}
	return 0;
}




