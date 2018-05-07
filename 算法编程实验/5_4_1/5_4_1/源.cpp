#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;
double a[maxn];

bool compare(double a,double b)
{
	return a > b;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("zojout.txt","w",stdout);
	int num;
	while(cin>>num)
	{
		for(int i = 0;i < num;i++)
			cin>>a[i];
	
		sort(a,a + num,compare);
		
		double res = a[0];
		for(int i =1;i < num;i++)
		{
			res *= a[i];
			res = sqrt(res) * 2;
		}
	
		printf("%.3lf\n",res);
	}
	return 0;
}