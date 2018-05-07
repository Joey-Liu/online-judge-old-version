#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
const int NUM = 100 + 10;

int main()
{
//	freopen("6in4.txt","r",stdin);
//	freopen("output4.txt","w",stdout);
	int num =0;
	cin>>num;
	//cin.get();
	while(num)
	{

		int a[NUM] ={0};
		int n;
		string s;
		cin>>s;
		n=s.length();
		for(int i=0;i < n;i++)
		    a[i] =s[n-1-i] - '0';
		while(true)
		{
			string ss;
			cin>>ss;
			if("0"==ss)
				break;
			int temp[NUM] = {0};
			int pn = ss.length();
			for(int j=0;j < pn;j++)
				temp[j] =ss[pn-1-j] - '0';
				
			int i=0;					//i用来对相加进行计数,n为和的位数，pn为加数的位数
			n = n > pn ? n : pn;
			for(i =0;i < n;i++)
			{
				a[i] += temp[i];
				if(a[i] > 9)
				{
					a[i+1]++;
					a[i] = a[i] -10;
				}
			}
			if(a[n] > 0)
				n++;
		}	
		for(int i = n-1;i >=0;i--)
			printf("%d",a[i]);
		printf("\n");
		if(num != 1)
			printf("\n");
		num--;
	}//system("pause");
	return 0;
}
