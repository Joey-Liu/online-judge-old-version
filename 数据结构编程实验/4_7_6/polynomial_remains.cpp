#include <iostream>
#define SIZE 10000
using namespace std;

int main()
{
	int n,k;
	int a[SIZE];
	
	cin>>n>>k;
	while(-1!=n && -1!=k)
	{
		for(int i=0;i<=n;i++)
	    	cin>>a[i];
        
		while(n>=k)
		{
		    //a[n]=0;
			a[n-k]=a[n-k]-a[n];
			a[n]=0;
			while(n>=0 && !a[n])
				n--;
		}
		if(n<0)
			cout<<0;
		else
			for(int i=0;i<=n;i++)
				cout<<a[i]<<' ';
		
		cout<<endl;
		cin>>n>>k;
	}
	return 0;
}
