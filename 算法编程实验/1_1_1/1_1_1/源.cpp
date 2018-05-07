#include <iostream>
#include <math.h>
using namespace std;

void solve(int year)
{
	double k = (year - 1960)/10 + 2;
	k = pow((double)2,k);
	double tmp = 0.0;
	int n = 2;

	while(tmp < k)
	{
		tmp += (log((double)n)/log((double)2));
		if(tmp > k)
			break;
		n++;
	}
	cout<<n - 1<<endl;
}

int main()
{
	freopen("B.1.dat","r",stdin);
	freopen("out.txt","w",stdout);
	int num;
	double m = log((double)4);
	m++;
	while(cin>>num && num != 0)
		solve(num);
	return 0;
}