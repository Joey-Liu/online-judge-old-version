#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
const int maxn=10000;
//long int next[maxn];
void getnext(char p[],int next[])
{
	long i,j=-1;
	next[0] = -1;
	for(i=0;i<strlen(p);)
	{
		while(j != -1 && p[j] != p[i])	//jÏàµ±ÓÚnext
			j=next[j];
		next[i+1] = j+1;
		i++;
		j++;
	}

}

int main()
{
	char s[maxn];
	memset(s,0,maxn*sizeof(char));
	cin.getline(s,maxn - 1);
	while(0 != strcmp(".",s))
	{
		int next[maxn] = {0};
		getnext(s,next);
		int n = strlen(s);
		if(0==n%(n - next[n]))
			cout<<n/(n - next[n])<<endl;
		else
			cout<<1<<endl;
		cin.getline(s,maxn - 1);
	}
	system("pause");
	return 0;
}