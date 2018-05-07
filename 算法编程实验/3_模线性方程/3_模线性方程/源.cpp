#include <iostream>
using namespace std;

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


void MLES(int a,int b,int n)// ax = b (mod n)
{
	int x ,y ,d;
	d = exgcd(a,n,x,y);
	if(0==b % d)
	{
		int xt = x * (b / d) % n;//方程的一个解
		cout<<"方程的解： "<<endl;
		for(int i = 0;i < abs(d);i++)
			cout<<xt + i * abs( (n / d) )<<" ";
		cout<<endl;
	}
	else
		cout<<"no solution"<<endl;
}

int main()
{
	int a,b,n;
	while(cin>>a>>b>>n)
		MLES(a,b,n);
	return 0;
}