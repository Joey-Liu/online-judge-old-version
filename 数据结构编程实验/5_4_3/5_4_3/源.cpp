#include <iostream>
const int maxn = 15;
int ans[maxn];
using namespace std;

int main()
{
	freopen("joseph.in","r",stdin);
	freopen("output.txt","w",stdout);
		int n=0;
		int k = 1;
		int r1 = 0,r2 = 0;					//记录两种方式出队位置
		int m1 = 0,m2 = 0;				    //两种出对方式
		for(k = 1;k <= maxn -1; k++)			//枚举每种k的出队顺序///////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		{
			bool ok_1 = true,ok_2 = true;
		//	int m1 = 0,m2 = 0;				//两种出对方式
			r1 = r2 =0;						//
			int s =1;
			for(s = 1;;s++)							//方案一或二成功是，退出循环
			{
				ok_1 = true;						//每次循环初始化为true
				ok_2 = true;
				m1= s * (k + 1);
				m2 =s * (k + 1) - k;
				r1 = r2 =0;							//每次也要初始化！！！
				int j = 0;
				for(j =0;j < k;j++)				//出队k次
				{
					r1 = (r1 + m1 -1)%(2*k - j);
					r2 = (r2 + m2 -1)%(2*k - j);
					if(r1 < k)						//方案一出错
					{
						ok_1 = false;
					}
					if(r2 < k)						//方案二出错
					{
						ok_2 = false;
					}
					if(!ok_1 && !ok_2)				//1,2均出错时，没有必要进行
					{
						break;
					}
				}
				if(ok_1 || ok_2)					//1 || 2方案正确时，跳出循环
				{
					break;
				}
			}
			if(ok_1 && ok_2)
			{
				ans[k] = m1 > m2 ? m2 : m1;
		//		cout<<ans[k]<<endl;
			}
			else if(ok_1)
			{
				ans[k] = m1;
		//		cout<<m1<<endl;
			}
			else if(ok_2)
			{
				ans[k] = m2;
			//	cout<<ans[k]<<endl;
			}
		}
		/*
		for(int i =1;i < maxn -1;i++)
			cout<<ans[i]<<endl;
		*/
		cin>>n;
		while(n)
		{
			cout<<ans[n]<<endl;
			cin>>n;
		}
	system("pause");
	return 0;
}
