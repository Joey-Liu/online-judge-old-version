#include <iostream>
#include <math.h>
using namespace std;
const int num = 20;
int s[1<<num];
int main()
{
	int D,I;
	while(cin>>D>>I)
	{
		memset(s,0,sizeof(s));			//开关初始时为关
		int k=1,n=(1<<D) - 1;				//n为结点数量
		for(int i=0;i < I;i++ )
		{
			k = 1;						//结点从1开始编号
			for(;;)
			{
				s[k] = !s[k];		//开关翻转
				k = s[k] ? 2*k : 2*k +1;
				if(k > n)
					break;				//落出叶子结点
			}
		}								//中间过程是模拟i个小球下落过程开关的变化
		cout<<k/2<<endl;			
	}
	system("pause");
	return 0;
}
