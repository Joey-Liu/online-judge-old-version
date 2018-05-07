#include <iostream>
#include <math.h>
using namespace std;
__int64 dis,step;

__int64 exgcd(__int64 a,__int64 b,__int64 & x,__int64 & y)// a > b
{
	if(0==b)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		__int64 xt,yt,ret = 0;
		ret = exgcd(b,a % b,xt,yt);
		x = yt;
		y = xt - (a / b ) * yt;
		return ret;
	}
}

void MLES(__int64 a,__int64 b,__int64 n)// ax = b(mod n)
{
	__int64 x, y ,d;
	d = exgcd(a,n,x,y);
	if(0== b % d)
	{
		__int64 xt = x * (b / d) % n;
		while(xt < 0)
			xt += (n / abs((double)d));
		cout<<xt<<endl;
	}
	else
		cout<<"Impossible"<<endl;
}

int main()
{
	freopen("FROG.IN9","r",stdin);
	freopen("out.txt","w",stdout);
	__int64 px,py,m,n,L;
	while(cin>>px>>py>>m>>n>>L)
	{
		 dis = (py - px) % L;//第二只 相对于第一只的 距离
		 step = (m - n) % L;//第一只 的步进速度
		if(dis==0)
			cout<<0<<endl;
		else if(0==step)
			cout<<"Impossible"<<endl;
		else
			MLES(step,dis,L);
	}
	return 0;
}