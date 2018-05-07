#include <iostream>
using namespace std;

const int maxn = 350;
double length[maxn];

int main()
{
	freopen("hangover.in","r",stdin);
	freopen("out.txt","w",stdout);
	memset(length,0,sizeof(length));

	for(int i = 1;i < maxn;i++)
		for(double j = 2;j <= i + 1;j++)
			length[i] += 1.0 / j;

	double que;
	while(cin>>que && que != 0.0)
	{
		int lp = 1,rp = maxn - 1;
		int mid = (lp + rp) / 2;

		while(lp + 1 < rp)
		{
			if(length[mid] > que)
				rp = mid;
			else if(length[mid] < que)
				lp = mid;
			mid = (lp + rp) / 2;
		}
		if(length[lp] > que)
			cout<<lp;
		else
			cout<<rp;
		cout<<" card(s)"<<endl;
	}//while cin
	return 0;
}