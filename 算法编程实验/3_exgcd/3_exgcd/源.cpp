#include <iostream>
using namespace std;

int a,b;

int exgcd(int a,int b,int & x,int & y) //a > b
{
	if(b==0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int xt,yt,ret = 0;
		ret = exgcd(b,a % b,xt,yt);
		x = yt;
		y = xt - (a / b) * yt;
		return ret;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		int x = 0,y = 0;
		cin>>a>>b;
		cout<<exgcd(a,b,x,y)<<" "<<"x = "<<" y = "<<endl;
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}