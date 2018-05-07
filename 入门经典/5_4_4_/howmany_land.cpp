#include <iostream>
using namespace std;
int main()
{
	//int n,v,e,f;	//v 顶点数  e 线段数 f土地数目，n椭圆上点数
	//v=e=f=0;
	int n=0;
	cin>>n;
	while(n)
	{
		long v,e,f;
		v=e=f=0;
		for(long i=0;i<=n-2;i++)
			v=v+i*(n-2-i);
		v=v*n/4+n;
		for(long j=0;j<=n-2;j++)
			e=e+(j*(n-2-j)+1);
		e=e*n/2+n;
		f=e-v+1;
		cout<<f<<endl;
		cin>>n;
	}
	system("pause");
	return 0;
}




