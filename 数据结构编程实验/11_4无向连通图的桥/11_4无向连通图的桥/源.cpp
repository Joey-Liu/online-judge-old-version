#include <iostream>
using namespace std;

const int maxn = 50;
int map[maxn][maxn];//�����㿪ʼ�洢
int pa[maxn];//DFS ������
int adj[maxn];//������,�����жϸ��ڵ�
int pre[maxn];//����ʱ��
int low[maxn];//�������ȷ���ʱ��
bool cut[maxn];//�Ƿ��� ���
int vi_time = 0;//������ʱ��

void init(int eg_num,int num_point)//�߸���
{
	memset(map,0,sizeof(map));
	int m,n;
	for(int i = 0;i < eg_num;i++)
	{
		cin>>m>>n;
		m--;n--;
		map[m][n] = map[n][m] = 1;
	}
	//��ʼ������ʱ
	memset(pre,-1,sizeof(pre));
	memset(pa,-1,sizeof(pa));
	memset(adj,0,sizeof(adj));
	memset(cut,false,sizeof(cut));
}

// ����ʼ������ʱ�� �� ���緢������ ��Ϊ 0

void find_bridge(int v,int fa)
{
	pre[v] = low[v] = vi_time++;//��ʼ������ʱ��� ��������
	for(int w = 0;w < maxn;w++)
	{
		if(1==map[v][w] && v != w && w != fa)
		{
			if(-1==pre[w])//���v-w Ϊ��֦��
			{
				find_bridge(w,v);
				if(low[w]==pre[w] || low[w] > pre[v] )
					cout<<v<<"-"<<w<<endl;
				low[v] = min(low[v],low[w]);
			}
			else//�����
				low[v] = min(low[v],pre[w]);
		}// if map==1
	}//for int w
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int node,edges;
	while(cin>>node>>edges)
	{
		if(node || edges)
		{	
			init(edges,node);
			vi_time = 0;

			//���㿪ʼ dfs
			pre[0] = low[0] = vi_time;
			
			find_bridge(0,-1);
			cout<<endl<<endl;
		}
		else
			break;
	}
	return 0;
}