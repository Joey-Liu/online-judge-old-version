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
typedef vector<ivec> imat;//�ڽӾ���
int num;//�ڵ����

void rise(int ro,imat & adj)
{
	char ch = getchar();
	while(true)
	{
		if('('==ch)//��ʼ���ڶ��ӽڵ�
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
			return;//������������������
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
		num = 1;//������
		int troot;
		cin>>troot;
		rise(troot,adj);
		//solve(adj);
	}
}
*/

priority_queue<int ,ivec,greater<int> > leafs;//�洢Ҷ�ڵ㣬С����

void solve(imat & adj)
{
	while(!leafs.empty())
		leafs.pop();
	//�Ƚ�Ҷ�ڵ����С����
	for(int i = 1;i <= num;i++)
	{
		if(1==adj[i].size())
			leafs.push(i);
	}

	for(int i = 0;i < num - 1;i++)//����num - 1 �����
	{
		int tmp = leafs.top();
		leafs.pop();
		int parent = *(adj[tmp].begin() );
		cout<<parent<<" ";

		//������β�̫����
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
		num = 1;//�ڵ�����
		int troot;
		cin>>troot;
		rise(troot,adj);
		solve(adj);
	}
	return 0;
}