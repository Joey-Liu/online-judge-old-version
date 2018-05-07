#include <iostream>
using namespace std;

int N,M,xb,yb,xa,ya;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>N>>M>>xb>>yb)
	{
		xa = N - xb;
		ya = M - yb;
		if(xa==xb && ya==yb)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}