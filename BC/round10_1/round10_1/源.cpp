#include <iostream>
#include <math.h>
using namespace std;

const double s1 = (1.0 + sqrt(5.0)) / 2;
const double s2 = (1.0 - sqrt(5.0)) / 2;
const double t1 = (1.0 - sqrt(5.0)) / 2;
const double t2 = (1.0 + sqrt(5.0)) / 2;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	int a1,a2,c,index;

	double res;
	int ans;
	cin>>casenum;
	while(casenum--)
	{
		cin>>a1>>a2>>c;
		if(c==a1 || c==a2)
		{
			cout<<"Yes"<<endl;
			continue;
		}

		ans = 0,res = 0.0,index = 3;
		while(res < c)//依次带入通项
		{
			res = pow(s1,(double)index) * (a2 - t1 * a1) / (s1 * (t2 - t1));
			res -= pow(s2,(double)index) * (a2 - t2 * a1) / (s2 * (t2 - t1));
			ans = (int) (res + 0.5);
			
			if(ans==c)
				break;
			index++;
		}
		if(ans==c)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}