#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 50;
int a[maxn];
int b[maxn];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(cin>>n && (n != 0))
	{
		for(int i =1;i <= n;i++)
			cin>>a[i];
		for(int i =1;i <= n;i++)
			cin>>b[i];
		sort(a + 1,a + 1 + n);
		sort(b + 1,b + n + 1);

		int tl = 1,tr = n;
		int ql = 1,qr = n;
		int res = 0;

		while(tl <= tr)
		{
			if(a[tl] < b[ql])//如果田忌的慢马 慢于 齐王的慢马 让他vs 齐王快马‘
			{
				tl++;
				qr--;
				res -= 200;
			}
			else if(a[tl]==b[ql])//两匹慢马相同，还是让慢马 vs 齐王快马
			{
				while(tl <= tr && ql <=qr)
				{
					if(a[tr] > b[qr])//田忌快马 vs 齐王快马
					{
						tr--,qr--;
						res += 200;
					}
					else
					{
						if(a[tl] < b[qr])
						{
							res -= 200;
						}
						tl++;
						qr--;
						break;
					}
				}//while 
			}
			else
			{
				tl++;
				ql++;
				res += 200;
			}
		}//whiletl < tr
		cout<<res<<endl;
	}//cin
	return 0;
}