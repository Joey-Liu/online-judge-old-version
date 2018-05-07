#include <iostream>
using namespace std;

const int maxn = 1000000 + 10;
int u[maxn];//É¸×Ó
int su[maxn];
int num = 1;//³¬Î²

void prime()
{
	memset(u,true,sizeof(u));
	for(int i = 2;i <= maxn;i++)
	{
		if(u[i])
			su[num++] = i;
		for(int j = 1;j < num;j++)
		{
			if(i * su[j] > maxn)
				break;
			u[i * su[j]] = false;
			if(i % su[j]==0)
				break;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	bool flag;
	int n;
	prime();
	while(cin>>n && n != 0)
	{
		flag = false;
		for(int i = 1;i <= num / 2;i++)
		{
			if(u[n - su[i]])
			{
				flag = true;
				cout<<n<<" = "<<su[i]<<" + "<<n - su[i]<<endl;
				break;
			}
		}
		if(!flag)
			cout<<"Goldbach's conjecture is wrong."<<endl;
	}
	return 0;
}