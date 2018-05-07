#include <iostream>
#include <vector>
using namespace std;

const int N = 10000 + 100;
vector<int> a[N];

int f[N],r[N];		//f为父节点指针，r为层次

void DFS(int u,int dep)
{
	r[u] = dep;
	for(vector<int>::iterator it = a[u].begin();it != a[u].end();it++)
		DFS(*it,dep+1);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int casement,num,n,i,x,y;
	scanf("%d",&casement);
	for(num =0;num < casement;num++)
	{
		scanf("%d",&n);
		for(int i=0;i < n;i++)
			a[i].clear();
		memset(f,-1,sizeof(f));//父节点应该改为-1

		for(int i=0;i< n -1;i++)
		{
			scanf("%d%d",&x,&y);
			a[x-1].push_back(y-1);
			f[y-1] = x - 1;
		}
		for(i =0;f[i] >= 0;i++)
		{
			;
		}
		DFS(i,0);

		scanf("%d%d",&x,&y);
		x--;
		y--;

		while(x != y)
		{
			if(r[x] > r[y])
				x = f[x];
			else
				y = f[y];
		}
		printf("%d\n",x + 1);
	}
	return 0;
}
