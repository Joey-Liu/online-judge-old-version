#include <iostream>
using namespace std;

const int maxn = 100 + 10;

int main()
{
	int loop;
	cin>>loop;
	while(loop--)
	{
		int a[maxn],b[maxn];
		int num;
		cin>>num;
		for(int i=0; i < num; i++)
			cin>>a[i];
		for(int i=0; i < num; i++)
			cin>>b[i];

		bool issta = true,isque = true;

		for(int i=0;i < num; i++)
		{
			if(a[i] != b[i])
				isque=false;			//	不按顺序输出时，则不满足队列形式
			if(a[i] != b[num-1-i])
				issta = false;
		}
		if(isque && issta)
			cout<<"both\n";
		else if(isque && !issta)
			cout<<"queue\n";
		else if(!isque && issta)
			cout<<"stack\n";
		else if(!isque && !issta)
			cout<<"neither\n";
	}
	system("pause");
	return 0;
}

