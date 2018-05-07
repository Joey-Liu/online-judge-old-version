#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <stdio.h>

using namespace std;
const int maxn = 50 + 5;

typedef vector<int> ivec;
typedef vector<ivec> imat;//邻接矩阵
int num;//节点个数

void rise(int ro,imat & adj)
{
	char ch = getchar();
	while(true)
	{
		if('('==ch)//开始存在儿子节点
		{
			int son;
			cin>>son;
			num++;
			adj[ro].push_back(son);
			adj[son].push_back(ro);
			rise(son,adj);
		}
		else if(')'==ch)
		{
			return;//结点所有子树构造完成
		}
		ch = getchar();
	}//while ch
}

/*
void init()
{
	//char tc;
	//imat adj(maxn,ivec());
	while(cin>>tc)
	{
		num = 1;//结点个数
		int troot;
		cin>>troot;
		rise(troot,adj);
		//solve(adj);
	}
}
*/

priority_queue<int ,ivec,greater<int> > leafs;//存储叶节点，小根堆

void solve(imat & adj)
{
	while(!leafs.empty())
		leafs.pop();
	//先将叶节点加入小根堆
	for(int i = 1;i <= num;i++)
	{
		if(1==adj[i].size())
			leafs.push(i);
	}

	for(int i = 0;i < num - 1;i++)//产生num - 1 次输出
	{
		int tmp = leafs.top();
		leafs.pop();
		int parent = *(adj[tmp].begin() );
		cout<<parent<<" ";

		//下面这段不太合适
		for(ivec::iterator it = adj[parent].begin();it != adj[parent].end();it++)
		{
			if(*it==tmp)
			{
				adj[parent].erase(it);
				break;
			}
		}
		if(1==adj[parent].size())
		{
			leafs.push(parent);
		}
	}
	cout<<endl;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("out.txt","w",stdout);
	char ch;
	while(cin>>ch)
	{
		imat adj(maxn,ivec());
		num = 1;//节点数量
		int troot;
		cin>>troot;
		rise(troot,adj);
		solve(adj);
	}
	return 0;
}