#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n>0)
	{
		int k=1,s=0;
		for(;;)
		{
			s+=k;
			if(s >= n)
			{
				cout<<s-n+1<<"/"<<k-s+n<<endl;
				break;
			}
			k++;
		}
	    cin>>n;
	}
	system("pause");
	return 0;
}

