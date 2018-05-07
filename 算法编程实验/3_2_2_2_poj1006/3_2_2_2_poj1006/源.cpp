#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
const int maxn = 4;

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


int MLES(int a,int n)// ax = b (mod n) 求a的逆元
{
	int x ,y ,d;
	d = exgcd(a,n,x,y);
	if(0==1 % d)
	{
		int xt = x * (1 / d) % n;//方程的一个解
		while(xt < 0)
			xt += n;
		return xt;
	}
}

int n[maxn] = {0,23,28,33};
int a[maxn],d,res,m[maxn],m2[maxn],c[maxn];
int tmp = 1;

void init()
{
	for(int i = 1;i < maxn;i++)
		tmp *= n[i];
	for(int i = 1;i < maxn;i++)
		m[i] = tmp / n[i];
	for(int i = 1;i < maxn;i++)
		m2[i] = MLES(m[i],n[i]);
	for(int i = 1;i < maxn;i++)
		c[i] = m[i] * (m2[i] % n[i]);
}

void solve()
{
	res = 0;
	for(int i = 1;i < maxn;i++)
		res += a[i] * c[i];
	if(res==0)
		res = tmp;
	else
		res %= tmp;

	int ti = res;
	res -= d;
	while(res <= 0)
		res += tmp;
	
	cout<<"the next triple peak occurs in "<<res<<" days."<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	int blocks;
	cin>>blocks;

	for(int blo = 0;blo < blocks;blo++)
	{
		cin>>a[1]>>a[2]>>a[3]>>d;
		//init();
		int casenum = 1;
		while(a[1] != -1 && a[2] != -1 && a[3] != -1 && d != -1)
		{
			cout<<"Case "<<casenum<<": ";
			solve();
			casenum++;
			cin>>a[1]>>a[2]>>a[3]>>d;
		}
		if(blo != blocks - 1)
			cout<<endl;
	}
	return 0;
}