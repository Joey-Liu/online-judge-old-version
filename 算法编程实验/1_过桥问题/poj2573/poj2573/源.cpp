#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;
int cost[maxn];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int num;
	while(cin>>num)
	{
		int tmp,res = 0;
		tmp = num;
		for(int i = 0;i < num;i++)
			cin>>cost[i];
		sort(cost,cost + num);
		
		while(num > 3)
		{
			if(cost[0] + cost[num - 2] < 2 * cost[1])//只用最快的 人传递手电筒
				res += cost[num - 1] + cost[0] + cost[num - 2] + cost[0];
			else//最快和次快的人传手电筒
				res += cost[1] + cost[0] + cost[num - 1] + cost[1];
			num -= 2;
		}

		if(1==num || 2==num)
			res += cost[num - 1];
		else if(3==num)
			res += cost[0] + cost[1] + cost[2];
		cout<<res<<endl;

		num = tmp;
		while(num > 3)
		{
			if(cost[0] + cost[num - 2] < 2 * cost[1])
				cout<<cost[0]<<" "<<cost[num - 1]<<endl<<cost[0]<<endl<<cost[0]<<" "<<cost[num - 2]<<endl<<cost[0]<<endl;
			else//最快和次快的人传手电筒
				cout<<cost[0]<<" "<<cost[1]<<endl<<cost[0]<<endl<<cost[num - 2]<<" "<<cost[num - 1]<<endl<<cost[1]<<endl;
			num -= 2;
		}
		if(num==2)
			cout<<cost[0]<<" "<<cost[1]<<endl;
		else if(num==1)//可能总共只有一个人坐船
			cout<<cost[0]<<endl;
		else
			cout<<cost[0]<<" "<<cost[2]<<endl<<cost[0]<<endl<<cost[0]<<" "<<cost[1]<<endl;
	}//while
	return 0;
}
