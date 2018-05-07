#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

typedef vector<int> ivec;
typedef vector<ivec> imat;//邻接矩阵类型

void print(imat & adj,int x,int p = 0)//p为上次输出的结点,默认值用于第一个函数调用,x为本次节点
{
	cout<<"("<<x;
	for(ivec::iterator it = adj[x].begin();it != adj[x].end();it++)
	{
		if(*it != p)
		{
			cout<<" ";
			print(adj,*it,x);
		}
	}
	cout<<")";
}

int main()
{
	freopen("decode.in","r",stdin);
	freopen("out.txt","w",stdout);
	string str;
	while(getline(cin,str))
	{
		istringstream ss(str);
		int x;
		ivec v;//输入序列

		while(ss>>x)
			v.push_back(x);
		int n = v.size() + 1;//树节点数

		ivec deg(n+1,0);//节点出度
		for(int i = 0;i < v.size();i++)
			deg[v[i]]++;
		
		priority_queue<int,ivec,greater<int> > leafs;
		for(int i = 1;i <= n;i++)//将初度为零的结点压入叶子节点
			if(deg[i] ==0)
				leafs.push(i);

		imat adj(n + 1,ivec());//临界矩阵
		for(int i = 0;i < n -1;i++)
		{
			int tmp = leafs.top();
			leafs.pop();

			adj[tmp].push_back(v[i]);
			adj[v[i]].push_back(tmp);
			if(0==--deg[v[i]])//则该节点变为叶子
				leafs.push(v[i]);
		}
		print(adj,n);
		cout<<endl;
	}
	return 0;
}