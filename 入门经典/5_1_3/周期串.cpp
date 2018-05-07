#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;

	int len=s.size();
	int i,j;
	bool flag=true;
	for(i=1;i<len; i++)
	{
		if(0 != len % i)
			continue;
		for(j=i;j<len;j++)
		{
			if(s[j%i] != s[j])
			{
				flag=false;
				break;
			}
			flag=true;
		}
		if(true==flag)
			break;
	}
	cout<<i<<endl;
	return 0;
}

