#include<iostream>
using namespace std;
int main()
{
	int n,i,sum=0;
	cin>>n;
	if(n>1)
		for(i=1;i<=n;i++)
			sum=sum+i;
	else
		for(;n<=1;n++)
			sum=sum+n;
	cout<<sum<<endl;
	return 0;
}

