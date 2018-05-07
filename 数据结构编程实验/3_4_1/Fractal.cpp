#include <iostream>
#include <math.h>
#define SIZE 15625
using namespace std;

bool p[SIZE][SIZE];

void print(int n,int x,int y)
{
	if(1==n)
	{
		p[x][y]=true;
			return;
	}
	else
	{
		int m=pow(3,n-2);
		print(n-1,x,y);
		print(n-1,x+2*m,y);
		print(n-1,x+m,y+m);
		print(n-1,x,y+2*m);
		print(n-1,x+2*m,y+2*m);
	}
}

int main()
{
	memset(p,false,sizeof(p));
	int n;
	cin>>n;
	while(n>0)
	{
		print(n,0,0);
		for(int i=0;i<pow(3,n-1);i++)
		{
			for(int j=0;j<pow(3,n-1);j++)
			{
				if(true==p[i][j])
					cout<<'X';
				else
					cout<<' ';
			}
			cout<<endl;
		}
		cout<<"-"<<endl;
		cin>>n;
	}
	return 0;
}