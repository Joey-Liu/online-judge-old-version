#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

const int maxn = 30 + 5;
char m[maxn];
using namespace std;

typedef map<string,int> record;
record h;
string s;
int n;					//总物种数
int main()
{
	freopen("C.4.dat","r",stdin);
	freopen("output4.txt","w",stdout);
	string name;
	int k = 0;
	n =0;
	while(1==scanf("%s",m))
	{
		n++;
		h[m]++;
	}
	for(record::iterator it = h.begin(); it != h.end();it++)
	{
		name = (*it).first;
		k = (*it).second;
		printf("%s %.4lf\n",name.c_str(),100 * (double)k/(double)n);
	}
	return 0;
}

