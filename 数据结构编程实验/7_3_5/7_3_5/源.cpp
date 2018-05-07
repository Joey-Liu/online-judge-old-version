#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;

const int maxn_peop = 20000 + 100;
const int maxn_dna = 20 + 5;
const int maxn = 20000 + 100;

char people[maxn_peop][maxn_dna];
int ank[maxn];

int cmp_string(const void* a,const void* b)
{
	char* s1 = (char*) a;
	char* s2 = (char* )b;
	return (strcmp(s1,s2));
}


int main()
{
	freopen("new.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int size,tmp;
	//cin>>size>>tmp;
	scanf("%d%d",&size,&tmp);
	while(size || tmp)
	{
		memset(people,0,sizeof(people));
		memset(ank,0,sizeof(ank));

		for(int i =0;i < size;i++)
			scanf("%s",people[i]);
		qsort(people,size,sizeof(people[0]),cmp_string);
	
		int k =1;
		for(int i =0;i < size;i++)//×îºó³¬ÏÂÎ²
		{
			if(0==strcmp(people[i],people[i+1]))
				k++;
			else
			{
				ank[k]++;
				k = 1;
			}
		}
		for(int i =1;i <= size;i++)
			printf("%d\n",ank[i]);
		
		scanf("%d%d",&size,&tmp);
	}

	return 0;
}