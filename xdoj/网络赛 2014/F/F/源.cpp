#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
const int maxn = 100 + 50;

int main()
{
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		string str;
		char lb[maxn],rb[maxn];
		memset(lb,0,sizeof(lb));
		memset(rb,0,sizeof(rb));

		cin>>str;
		for(int i= 0;i < str.size();i++)
		{
			if('0'==str[i])
				lb[i] = 'T';
			else
				lb[i] = '_';
		}

		int j =0;
		for(int i = str.size()-1;i >= 0;i--)
		{

			if('1'==str[i])
				rb[j++] = 'T';
			else
				rb[j++] = '_';
		}
		if(0==strcmp(lb,rb))
			cout<<"True"<<endl;
		else
			cout<<"False"<<endl;
	}
	system("pause");
	return 0;
}