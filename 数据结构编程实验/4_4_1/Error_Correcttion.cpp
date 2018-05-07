#include <iostream>
using namespace std;
const int maxl=512;

int n;
int a[maxl][maxl],row[maxl],col[maxl];
int read()
{
	int i,j=0;
	cin>>n;
	if(0==n)
		return 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	return 1;
}

void solve()
{
	int cc,cr,i,j,k1,k2;
	cc=cr=0;

	for(i=0;i<n;i++)
		row[i]=col[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			row[i]=row[i]+a[i][j];
			col[j]=col[j]+a[i][j];
		}
	for(i=0;i<n;i++)
	{
		if(row[i]%2)
		{	
			k1=i;
			cc++;
		}
		if(col[i]%2)
		{
			k2=i;
			cr++;
		}
	}
	if(0==cc && 0==cr)
		cout<<"OK";
	else if(1==cc && 1==cr)
		cout<<"Change bit "<<'('<<k1+1<<','<<k2+1<<')';
	else 
		cout<<"Corrupt";
	cout<<endl;
}

int main()
{
	while(read())
		solve();
	return 0;
}




