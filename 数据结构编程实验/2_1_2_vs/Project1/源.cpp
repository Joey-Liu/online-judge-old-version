#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n = 0;
	//bool flag = true;
	double time = 0,min;
	double v,t;
	cin>>n;
	while(n)
	{
		bool flag = true;
		for(;n > 0;n--)
		{
			cin>>v>>t;
			if(t < 0)
				continue;
			v = v / 3600.0;
			time = 4.5/v + t;
			if(flag)
			{
				min = time;
				flag = false;
			}
			if(time < min)
				min = time;
		}
		cout<<ceil(min)<<endl;
		cin>>n;
	}
	system("pause");
	return 0;
}
