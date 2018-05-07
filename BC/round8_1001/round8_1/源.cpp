#include <iostream>
#include <algorithm>
#define INF -1000000000
using namespace std;

const int maxn = 5000;
long long a[100 + 10];
long long sum[maxn];
int num;
int index;//和的个数 超尾
long long tmp;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>num)
	{
		memset(sum,0,sizeof(sum));
		long long res = 0;
		index = 1;
		for(int i = 1;i <= num;i++)
			cin>>a[i];

		for(int i = 1;i <= num;i++)
			for(int j = i + 1;j <= num;j++)
				sum[index++] = a[i] + a[j];

		sort(sum + 1,sum + index);
		long long  pre = INF;
		for(int i = 1;i < index;i++)
		{
			if(i != 1)
			{
				if(pre != sum[i])
				{
					res += sum[i];
					pre = sum[i];
				}
			}
			else
			{
				pre = sum[i];
				res += sum[i];
			}
		}
		cout<<res<<endl;
	}
	return 0;
}