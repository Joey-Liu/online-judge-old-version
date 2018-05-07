#include <iostream>
#include <string>
using namespace std;

const int maxn = 100 + 10;
int a[maxn] = {0};

int main()
{
	int n=0;
	cin>>n;
	while(n--)
	{
		string s;
		int ibase,obase;
		cin>>s;
		cin>>ibase>>obase;
		int n = s.size();
		for(int i =0;i < n;i++)
		{
			if(s[n -i-1] >='A' && s[n - i -1] <='Z')
				