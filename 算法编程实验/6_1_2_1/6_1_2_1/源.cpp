#include <iostream>
using namespace std;
const int maxn = 6000 + 10;

int a[maxn];//用前i中货币能够成 金额j的方案数
int b[11] = {1,2,4,10,20,40,100,200,400,1000,2000};

void work()
{
	//初始化 只用第0种货币 构成所有金额的方案数量为1
	for(int j = 0;j < maxn;j++)
			a[j] = 1;

	for(int i =1;i < 11;i++)//枚举用前i种货币
		for(int j = b[i];j < maxn;j++)
				a[j] += a[j - b[i]];
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	work();
	double mon;
	while(cin>>mon && mon != 0.0)
	{
		int tmp = (int)(mon * 20);
		cout<<mon<<"		"<<a[tmp]<<endl;
	}
	return 0;
}
