#include <iostream>
using namespace std;

const int maxn = 20000000 + 100;
const int maxsize = 100000 + 10;

bool u[maxn];
int res[maxsize];

void prime()
{
	memset(u,true,sizeof(u));
	u[0] = u[1] = false;

	for(int i = 2;i < maxn;i++)
	{
		if(u[i])
		{
			for(int j = 2;i * j < maxn;j++)
				u[i * j] = false;
		}
	}

	int index = 1;
	for(int i = 2;i < maxn;i++)
	{
		if(u[i] && u[i + 2])
		{
			res[index++] = i;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	prime();
	int num;
	while(cin>>num)
		cout<<"("<<res[num]<<", "<<res[num] + 2<<")"<<endl;
	return 0;
}