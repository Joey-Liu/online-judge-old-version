#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;
int N;//计算矩阵的N次幂
//const int maxn = 3;

struct matrix
{
	int a[3][3];
}origin,res;

matrix multiply(matrix x,matrix y)
{
	matrix temp;
	memset(temp.a,0,sizeof(temp.a));

	for(int i = 0;i < 3;i++)
		for(int j = 0;j < 3;j++)
			for(int k = 0;k < 3;k++)
				temp.a[i][j] += x.a[i][k] * y.a[k][j];

	return temp;
}

void init()
{
	cout<<"初始矩阵"<<endl;
	for(int i = 0;i < 3;i++)
	{
		for(int j = 0;j < 3;j++)
		{
			origin.a[i][j] = rand() % 10;
			cout<<origin.a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	//结果矩阵初始化为单位阵
	memset(res.a,0,sizeof(res.a));
	res.a[0][0] = res.a[1][1] = res.a[2][2] = 1;
}

void solve(int n)//计算矩阵的n次幂
{
	while(n)
	{
		if(n & 1)
			res = multiply(res,origin);
		n>>=1;
		origin = multiply(origin,origin);
	}
	cout<<N<<"次幂结果如下:"<<endl;
	for(int i = 0;i < 3;i++)
	{
		for(int j = 0;j < 3;j++)
			cout<<res.a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}


int main()
{
	while(cin>>N)
	{
		init();
		solve(N);
	}
	return 0;
}