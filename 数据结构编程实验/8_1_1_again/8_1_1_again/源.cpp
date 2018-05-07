#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10000 + 100;

vector<int> child[maxn];//���ӽڵ�

int parent[maxn];//�ڵ㸸ָ��
int layer[maxn];//�����
void DFS(int i,int n)			//��ȱ�ÿ���ڵ������
{
	layer[i] = n;
	for(vector<int>::iterator ptr = child[i].begin();ptr != child[i].end();ptr++)
		DFS(*ptr,n + 1);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int casetime;
	cin>>casetime;
	while(casetime--)
	{
		int node_num;
		cin>>node_num;
		memset(parent,-1,sizeof(parent));
		for(int i =0;i < node_num;i++)
			child[i].clear();
		
		int a,b;
		for(int i = 0;i < node_num - 1;i++)
		{
			cin>>a>>b;
			a--;b--;
			child[a].push_back(b);
			parent[b] = a;				//���ø���ָ����Ϣ
		}
		int i;
		for(i = 0;parent[i] >= 0;i++)
			;//�ҵ����ڵ�
		DFS(i,0); 

		int x,y;
		cin>>x>>y;
		x--;y--;
		while (x != y)
		{
			if(layer[x] > layer[y])
				x = parent[x];
			else
				y = parent[y];
		}
		cout<<x + 1<<endl;
	}
	system("pause");
	return 0;
}