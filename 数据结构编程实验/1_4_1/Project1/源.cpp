#include <iostream>
using namespace std;
const int maxn = 300;
const double delta = 1e-8;
int zero(double x)
{
	if(x > delta)
		return 1;
	else if(x < -delta)
		return -1;
	return 0;
}

int main()
{
	double len[maxn];
	int i;
	len[0] = 0.0;
	len[1] = 1.0/2.0;
	for(i =2; i < maxn;i++)
		len[i] = len[i-1] + 1.0/(i+1);
	double x;
	cin>>x;

	while(zero(x))
	{
		int l=0,r = maxn - 1;
		int mid = (l+r)/2;
		while(l + 1 < r)
		{
			if(zero(len[mid] - x) > 0)
			{
				r = mid;
				mid = (r+l)/2;
			}
			else if(zero(len[mid] - x) < 0)
			{
				l = mid;
				mid = (r+l)/2;
			}
			else
			{
				r = mid;
				break;
			}
		}
		cout<<r<<" card(s)"<<endl;
		cin>>x;
	}
	system("pause");
	return 0;
}

