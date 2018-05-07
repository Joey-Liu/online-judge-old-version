#include <iostream>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 100;
bool vis[maxn];
int step[maxn];

bool hasfind = false;
int n,k;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	memset(vis,false,sizeof(vis));
	memset(step,0,sizeof(step));
	cin>>n>>k;
	
	queue< int> que;
	que.push(n);
	int pos = -1;
	vis[n] = true;

	while(!hasfind)
	{
		pos = que.front();
		que.pop();

		if(pos==k)
			hasfind = true;
		else
		{
			if(pos - 1 >= 0 && !vis[pos - 1])
			{
				vis[pos - 1] = true;
				que.push(pos - 1);
				step[pos - 1] = step[pos] + 1;
			}
			if(pos + 1 <= 100000 && !vis[pos + 1])//刚开始写成else if ，自己也是醉了
			{
				vis[pos + 1] = true;
				que.push(pos + 1);
				step[pos + 1] = step[pos] + 1;
			}
			if(pos * 2 <= 100000 && !vis[pos * 2])
			{
				vis[2 * pos] = true;
				que.push(2 * pos);
				step[pos * 2] = step[pos] + 1;
			}
		}
	}
	cout<<step[pos];
	return 0;
}