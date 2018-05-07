#include <iostream>
using namespace std;
const int maxl=1000+5;
int compare(int a[],int la,int b[],int lb)
{
	if(la>lb)
		return 1;
	if(la<lb)
		return -1;
	for(int i=la-1;i>=0;i--)
	{
		if(a[i] && !b[i])
			return 1;
		else if(!a[i] && b[i])
			return -1;
	}
	return 0;
}

int main()
{
	int loop;
	cin>>loop;
	while(loop--)
	{
		int f[maxl],g[maxl],h[maxl],i,j=0;
		int lf,lg,lh;
		
		cin>>lf;
		for(i=lf-1;i>=0;i--)
			cin>>f[i];

		cin>>lg;
		for(i=lg-1;i>=0;i--)
			cin>>g[i];

		cin>>lh;
		for(i=lh-1;i>=0;i--)
			cin>>h[i];

		int sum[maxl+maxl],ls=lf+lg-1;
		for(i=0;i<ls;i++)
			sum[i]=0;
		for(i=0;i<lf;i++)
			for(j=0;j<lg;j++)
				sum[i+j]=sum[i+j]^ (f[i] && g[j]);
		while(compare(sum,ls,h,lh)>=0)
		{
			int d=ls-lh;
			for(i=0;i<lh;i++)
				sum[i+d]=sum[i+d]^h[i];
			while(ls && !sum[ls-1])
				ls--;
		}
		if(0==ls)
			ls=1;
		cout<<ls<<' ';
		for(i=ls-1;i>0;i--)
			cout<<sum[i]<<' ';
		cout<<sum[0]<<endl;
	}
	return 0;
}