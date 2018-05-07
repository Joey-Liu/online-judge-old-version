#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b;

	while(a && b)
	{
		int temp,count=0,c=0;
		while(a || b)
		{
			temp= a%10 +b%10+c;
			if(temp>9)
			{
				count++;
				c=1;
			}
			else
				c=0;
			a/=10;
			b/=10;
		}
		cout<<count<<endl;
		cin>>a>>b;
	}
	return 0;
}
