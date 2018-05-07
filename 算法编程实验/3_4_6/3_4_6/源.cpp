#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

typedef long long LL;

LL mod_pro(LL a,LL b,LL n)
{
	LL r,d;
	r = 0;
	d = a;
	while(b > 0)
	{
		if(b & 1)
			r = (r + d) % n;
		d = (d * 2) % n;
		b >>= 1;
	}
	return r;
}

LL mod_exp(LL a,LL b,LL n)
{
	LL r = 1,d = a;
	while(b)
	{
		if(b & 1)
			r = mod_pro(r,d,n);
		d = mod_pro(d,d,n);
		b >>= 1;
	}
	return r;
}

int lederang(LL a,LL p)
{
	a %= p;
	if(a==0)
		return 0;
	if(mod_exp(a,(p - 1) / 2,p)==1)
		return 1;
	return -1;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	LL a,p;
	while(cin>>a>>p && (a != -1 && p != -1))
	{
		/*
		if(1==mod_exp(a,(p - 1)/2,p))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		*/
		//注意，如果勒让德符号为零时，也可以进行分配
		if(lederang(a,p) < 0)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}