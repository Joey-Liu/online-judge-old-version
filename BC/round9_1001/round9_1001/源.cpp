#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 1000000 + 1000;
int exgcd(int a,int b,int & x,int & y)//a > b
{
	if(!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int ret =exgcd(b,a %b,y,x);
		y -= a / b * x;
		return ret;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int a,b,c;
	int x,y,r,dx,dy;//x,y原始解，r 为a，b gcd
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		int X1 = 1,X2 = maxn;
		int Y1 = 1,Y2 = maxn;
		cin>>a>>b>>c;
		if(a < b)
		{
			int tmp  = a;
			a = b;
			b = tmp;
		}
		r = exgcd(a,b,x,y);
		if(r==0)
		{
			if(c != 0)
				cout<<0<<endl;
			continue;
		}
		if(c % r != 0)
		{
			cout<<0<<endl;
			continue;
		}
		x *= c / r;
		y *= c / r;
		dx = b / r;
		dy = -1 * a / r;
		int lx,rx,ly,ry;

		X1 -= x;
		X2 -= x;
		Y1 -= y;
		Y2 -= y;
		
		if(dx > 0)
		{
			lx = ceil(double(X1) / dx);
			rx = floor(double(X2) / dx);
		}
		else
		{
			lx = ceil(double(X2) / dx);
			rx = floor(double(X1) / dx);
		}

		if(dy > 0)
		{
			ly = ceil(double(Y1) / dy);
			ry = floor(double(Y2) / dy);
		}
		else
		{
			ly = ceil(double(Y2) / dy);
			ry = floor(double(Y1) / dy);
		}
		
		int lp = max(lx,ly);
		int rp = min(rx,ry);
		if(rx < lx || ry < ly || rp < lp)
			cout<<0<<endl;
		else
			cout<<rp - lp + 1<<endl;
	}//while
	return 0;
}