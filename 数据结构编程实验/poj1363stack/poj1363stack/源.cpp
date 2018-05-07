#include <iostream>
using namespace std;

const int maxn = 1000 + 10;
int n[maxn];//出栈顺序
int a[maxn];
int num;

int main()
{
	freopen("rails.in","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>num && num != 0)
	{
		while(cin >>n[1] && n[1] != 0)
		{
			bool flag = true;
			for(int i = 2;i <= num;i++)
				cin>>n[i];
			int index = 1,tp = 0;//count符合数量
			for(int i = 1;i <= num;)
			{
				if(n[i] < index)//在栈中寻找
				{
					if(tp != 0 && a[tp - 1]==n[i])
					{
						tp--;
						i++;
					}
					else
					{
						flag = false;
						cout<<"No"<<endl;
						break;
					}
				}
				else if(n[i]==index)
				{
					i++;
					index++;
				}
				else//n[i] > index
				{
					while(index != n[i])
					{
						a[tp++] = index;
						index++;
					}
					i++;
					index++;
				}
			}
			if(flag)
				cout<<"Yes"<<endl;
		}//while cin>>n[1]
		cout<<endl;
	}//cin>>num
	return 0;
}