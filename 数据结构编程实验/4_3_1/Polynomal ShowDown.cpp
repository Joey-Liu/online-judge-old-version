#include <iostream>
using namespace std;
inline int fabs(int k)
{
	return (k < 0 ? -k : k);
}

int main()
{
	int a[9];
	int n=9;
	while(cin>>a[0])
	{
		for(int i=1;i<9;i++)
			cin>>a[i];
		bool first=true;
		for(int j=0;j<9;j++)			//从此都用j表示
		{
			if(a[j])
			{
				if(true==first)
				{
					if(-1==a[j] && j< n-1)
						cout<<'-';
					else if(1!=a[j] || j==8)
						cout<<a[j];
					if(7==j)
						cout<<'x';
					else if(j<8)
						cout<<"x^"<<n-j-1;
					first=false;
				}
				else
				{
					cout<<' ';
					cout<<(a[j] < 0 ? '-' : '+')<<' ';
					if(1!=fabs(a[j]) || n-1==j)
						cout<<fabs(a[j]);
					if(7==j)
						cout<<'x';
					else if(j<8)
						cout<<"x^"<<n-j-1;
				}
			}
		}
		if(true==first)
			cout<<0;
		cout<<endl;
	}
	return 0;
}

