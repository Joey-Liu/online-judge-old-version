#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

typedef vector<int> ivec;
typedef vector<ivec> imat;//�ڽӾ�������

void print(imat & adj,int x,int p = 0)//pΪ�ϴ�����Ľ��,Ĭ��ֵ���ڵ�һ����������,xΪ���νڵ�
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
		ivec v;//��������

		while(ss>>x)
			v.push_back(x);
		int n = v.size() + 1;//���ڵ���

		ivec deg(n+1,0);//�ڵ����
		for(int i = 0;i < v.size();i++)
			deg[v[i]]++;
		
		priority_queue<int,ivec,greater<int> > leafs;
		for(int i = 1;i <= n;i++)//������Ϊ��Ľ��ѹ��Ҷ�ӽڵ�
			if(deg[i] ==0)
				leafs.push(i);

		imat adj(n + 1,ivec());//�ٽ����
		for(int i = 0;i < n -1;i++)
		{
			int tmp = leafs.top();
			leafs.pop();

			adj[tmp].push_back(v[i]);
			adj[v[i]].push_back(tmp);
			if(0==--deg[v[i]])//��ýڵ��ΪҶ��
				leafs.push(v[i]);
		}
		print(adj,n);
		cout<<endl;
	}
	return 0;
}