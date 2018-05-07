//hack data：0 1
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100 + 20;

int a[maxn];
bool used[maxn];
int num;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int last_num;
	bool flag = false;
	while(cin>>num)
	{
		flag = false;
		memset(used,false,sizeof(used));

		for(int i = 0;i < num;i++)
			cin>>a[i];
		sort(a,a + num);

		for(int i = 0;i < num;i++)
		{
			if(a[i] % 2 && i != num - 1)//hack a[i] 不能是唯一的首字
			{
				last_num = a[i];
				used[i] = true;
				flag = true;
				break;
			}
		}
		if(!flag)
			cout<<"-1"<<endl;
		else
		{
			for(int i = num - 1;i >= 0;i--)
				if(!used[i])
					cout<<a[i];
			cout<<last_num<<endl;
		}
	}
	return 0;
}

