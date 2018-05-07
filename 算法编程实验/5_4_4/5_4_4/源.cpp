#include <iostream>
using namespace std;

const int maxn = 50 + 20;
int a[maxn];
int main()
{
	freopen("bricks.in","r",stdin);
	freopen("out.txt","w",stdout);
	int n,sum = 0;
	int casenum = 1;
	while(cin>>n && n!= 0)
	{
		sum = 0;
		for(int i = 0;i < n;i++)
		{
			cin>>a[i];
			sum += a[i];
		}
		int res = 0,ave = 0;
		ave = sum / n;
		for(int i = 0;i < n;i++)
			if(a[i] > ave)
				res += (a[i] - ave);
		cout<<"Set #"<<casenum++<<endl;
		cout<<"The minimum number of moves is"<<res<<endl<<endl;
	}
	return 0;
}