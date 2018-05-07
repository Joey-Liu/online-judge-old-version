#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

const int maxn = 100 + 20;
int a[maxn],b[maxn];
int n1,n2,mn;				//mn用来存和的位数

void strtoi(string s,int c[],int & n)
{
	n = s.size();
	for(int i =0; i < n;i++)
	{
		if(s[n -i -1] >= 'a' && s[n -1-i] <='j')
			c[i] = s[n -1 -i] - 'a' + 10;
		else
			c[i] = s[n -i -1] - '0';
	}
}

void sum(int a[],int b[],int & big)
{
	big = n1 > n2 ? n1 : n2;
	for(int i =0;i < big;i++)
	{
		a[i] += b[i];
		if(a[i] > 19)
		{
			a[i+1] += a[i]/20;
            a[i] = a[i]%20;
		}
	}
	if(a[big] > 0)			
		big++;				//更新和的位数
}

void print(int a[])
{
	for(int i = mn -1;i >=0; i--)
	{
		if(a[i] < 10)
			cout<<a[i];
		else
			cout<<(char)(a[i] + 87);
	}
}

int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));

		strtoi(s1,a,n1);
		strtoi(s2,b,n2);
		sum(a,b,mn);			//更新n1，n2，mn

		print(a);
		cout<<endl;
	}
	return 0;
}