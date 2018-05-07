#include <iostream>
#include <stdio.h>
#define NUM 1000001
unsigned int g[NUM];
using namespace std;
int sum_of_digital(unsigned int n)
{
	if(n < 10)
		return n;
	else
		return (n%10) + sum_of_digital(n/10);
}

void sequeue(unsigned int n)
{
	int next=0;
	next =n + sum_of_digital(n);
	while(next < NUM)		//next可能之前已经设置过了
	{
		if(g[next]!=next)
			return;
		g[next]=n;
		next += sum_of_digital(next);
	}
}

/*
void sequeue(unsigned n)
{
	while(n < NUM)
	{
		unsigned next=n + sum_of_digital(n);
		if(next > NUM || g[next]!=next)
			return;
		g[next]=n;
		n=next;
	}
}
*/

int main()
{
//	freopen("output.txt","w",stdout);
	unsigned i=1,j=1;
	for(i=1;i<NUM;i++)
		g[i]=i;
	while(j < NUM)
	{
		sequeue(j);
		j++;
	}
	for(i=1;i < NUM;i++)
		if(i==g[i])
			printf("%d\n",i);
	system("pause");
	return 0;
}
