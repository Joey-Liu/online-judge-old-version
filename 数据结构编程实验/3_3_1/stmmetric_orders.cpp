#include <iostream>
#include <string>
#define SIZE 20
using namespace std;

int main()
{
	string name[SIZE];
	int n,m,loop=1;
	cin>>n;
	while(n)
	{
		m= (0==n%2) ? (n-1) : n;
		for(int i=1;i<=n;i++)
			cin>>name[i];
		cout<<"SET "<<loop++<<endl;
		
		for(int in=1;in<=m;in+=2)
			cout<<name[in]<<endl;
		
		int l= (0==n%2) ? n:(n-1);
		for(;l>=2;l-=2)
			cout<<name[l]<<endl;
		cin>>n;
	}
	return 0;
}


