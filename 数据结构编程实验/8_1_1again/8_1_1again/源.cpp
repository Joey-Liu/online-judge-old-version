#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int N = 10000;
vector<int> a[N];
int f[N],r[N];

void DFS(int u,int dep)
{
	r[u] = dep;
	for(vector<int>::iterator it = a[u].begin();it != a[u].end();it++)
		DFS(*it,dep + 1);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum,num,x,y,node,root;
	cin>>casenum;
	for(num = 0;num < casenum;num++)
	{
		for(int i = 0;i < N;i++)
			a[i].clear();
		memset(f,-1,sizeof(f));

		cin>>node;
		for(int i = 0;i < node -1;i++)
		{
			cin>>x>>y;
			a[x - 1].push_back(y - 1);
			f[y - 1] = x - 1;
		}
		for(root = 0;f[root] >= 0;root++)
			;
		DFS(root,0);

		cin>>x>>y;
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
	}//casenum for
	return 0;
}