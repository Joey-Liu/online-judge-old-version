#include <iostream>
#include <sstream>
#include <string>
#include <memory.h>

const int maxn = 50 + 10;
const int camaxn = 20;

using namespace std;

int main()
{
	//freopen("mash_in.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	string s;
	int loop =1;
	while(getline(cin,s))
	{
		if(s.size()==0)
		{
			cout<<endl;
			continue;
		}
		istringstream ss(s);

		int num,m;					//num为士兵人数，m为幸运位置
		
		bool del[maxn];				//士兵数组
		int card[camaxn];
		int k=0;			//卡片指针
		memset(del,false,sizeof(del));				//全在队中
		
		ss>>num>>m;
		for(int i=0; i < camaxn; i++)
			ss>>card[i];
		int cur = num;					//在队人数
		int count = 0;					//计数

		bool flag = false;
		while(cur > m)
		{
			for(int i=0; i < num;i++)
			{
				if(false==del[i])
				{
					count++;
				}
				if(count==card[k])
				{
					del[i] = true;
					cur--;
					count = 0;
				}
				if(cur==m)
				{
					flag = true;
					break;
				}
			}
			k++;
			count = 0;
			if(true==flag)
				break;
		}
		cout<<"Selection #"<<loop<<endl;
		loop++;
		for(int i=0; i < num;i++)
			if(false==del[i])
				cout<<i+1<<" ";
		cout<<endl;

		cout<<endl;
	}
	system("pause");
	return 0;
}