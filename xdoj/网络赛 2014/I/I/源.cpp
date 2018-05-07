#include <cstdio>
#include <memory.h>
#include <vector>

using namespace std;
const int maxn = 100 + 5;
int parent[maxn];
int layer[maxn];
vector<int> son[maxn];//�洢���ӽ��
bool path[maxn];

void DFS(int node,int dep)//�ݹ����ø����ڵ���
{
	layer[node] = dep;
	for(vector<int> ::iterator it = son[node].begin();it != son[node].end();it++)
		DFS(*it,dep + 1);
}

int find(int a,int b)//����a��b�Ĺ�ͬ����
{
	while(a != b)
	{
		path[a] = true;
		path[b] = true;//���·��
		if(layer[a] > layer[b])
			a = parent[a];
		else
			b= parent[b];
	}
	return a;//��ͬ����
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i = 0;i < n;i++)	
			son[i].clear();//ÿ�����ӽڵ��ʼ��Ϊ��
		memset(parent,-1,sizeof(parent));//��ĸ����ʼ��Ϊ-1

		int u,v;
		for(i = 0;i < n - 1;i++)
		{
			scanf("%d%d",&u,&v);
			u--;v--;////////////
			son[u].push_back(v);
			parent[v] = u;
		}
		
		for(i = 0;parent[i] > 0;i++)
			;//�ҵ����ڵ�
		DFS(i,0);//���ø����ڵ���
		
		int m;
		scanf("%d",&m);//m��ѯ��

		for(i = 0;i < m;i++)//Ӧ�ð�ÿ��·����ΪFALSE
		{
			memset(path,false,sizeof(path));
			int x ,y ,z;
			scanf("%d %d %d",&x,&y,&z);
			x--;y--;z--;

			int pre = find(y,z);
			
			int root = x;//�����µ�·��,��COM��root����root�Ƿ� ����ʱ��·��
			int com = y;
			bool flag = false;
			bool apend = false;

			if(root == y || root == z)//������� ����һ�ڵ���ͬ����ô���Ⱦ��Ǹ��ڵ�
			{
				flag =true;
				apend = true;
			}

			while(root != com && apend == false)//�����ڵ� �� y��z ��ֱ����ϵʱ������·������
			{
				if(layer[root] > layer[com])
				{
					root = parent[root];
					if(true==path[root])
					    {flag = true;break;}
				}
				else
					com = parent[com];	
			}
			if(true==flag)//////////////////////////////
				printf("%d\n",root + 1);//��ͬ����
			else
				printf("%d\n",pre + 1);//ԭ��ͬ����
		}
	}//while
	return 0;
}