#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef long long LL;

LL A,B,C,D,k,n;

LL exgcd(LL a,LL b,LL & x,LL & y) //a > b
{
	if(b==0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		LL xt,yt,ret = 0;
		ret = exgcd(b,a % b,xt,yt);
		x = yt;
		y = xt - (a / b) * yt;
		return ret;
	}
}

//计算Cx=D(mod n)是否有解
void solve()
{
	n = (1LL)<<k;
	D = (B - A) % n;
	if(D < 0)
		D += n;

	if(D==0)
	{
		cout<<"0"<<endl;
		return;
	}
	if(C==0)
	{
		cout<<"FOREVER"<<endl;
		return;
	}

	LL x,y,d;
	d = exgcd(C,n,x,y);

	if(0 == (D % d))
	{
		LL xt = x * (D / d) % n;
		
		while(xt < 0)
			xt = (xt + (n / abs(d))) % n;
		while(xt > 0)
			xt = (xt - (n / abs(d))) % n;

		xt = (xt + (n / abs(d))) % n;
		cout<<xt<<endl;
	}
	else
		cout<<"FOREVER"<<endl;
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>A>>B>>C>>k;
	while(A || B|| C||k)
	{
		solve();
		cin>>A>>B>>C>>k;
	}
	return 0;
}
