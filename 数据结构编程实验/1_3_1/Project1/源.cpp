#include <iostream>
#include <math.h>
const double M=3.14159265;
using namespace std;

int main()
{
	int loop;
	cin>>loop;
	int i=1;
	while(loop--)
	{
		double x,y;
		cin>>x>>y;
		double ans = (x*x + y*y) * M/2;
		ans=ans / 50;
		ans=ceil(ans);
		cout<<"Property "<<i<<": This property will begin eroding in year "<<ans<<".\n";
		i++;
	}
	cout<<"END OF OUTPUT.";
	system("pause");
	return 0;
}
