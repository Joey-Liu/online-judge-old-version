#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 150;
int num[maxn];

void solve(int n)
{
	if(1==n)
	{
		cout<<"DEFICIENT"<<endl;
		return;
	}
	int res = 0;
	for(int i = 1;i <= sqrt((double)n);i++)
	{
		if(n % i==0)
		{
			res += i;
			if(i==1 || i== (n / i))
				continue;
			res += n / i;
		}
	}
	if(res==n)
		cout<<"PERFECT"	<<endl;
	else if(res < n)
		cout<<"DEFICIENT"<<endl;
	else
		cout<<"ABUNDANT"<<endl;
}

int main()
{
	freopen("382.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tm ,cnt = 0;
	cin>>tm;
	while(tm != 0)
	{
		num[cnt++] = tm;
		cin>>tm;
	}

	cout<<"PERFECTION OUTPUT"<<endl;
	for(int i = 0;i < cnt;i++)
	{
		cout.setf(ios::right);
		cout.width(5);
		cout<<num[i];
		
		cout.unsetf(ios::right);
		cout<<"  ";
		solve(num[i]);
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}