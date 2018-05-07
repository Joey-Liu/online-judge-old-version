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
//�ӽڵ�v��ʼ dfs ������,fa Ϊv ���� ��ָ��
//��Ϊ���ڼ�ͼ��û�ж��رߣ����� ʹ�ø�ָ�� ������� �����ڵķ����
void find_cut_point(int v,int fa)
{
	pre[v] = low[v] = vi_time++;//���÷���ʱ�� �� �������� �ĳ�ʼֵ
	for(int w = 0;w < maxn;w++)
	{
		if(1==map[v][w] && v != w && w != fa)//������������,��ֹ�����Ի�· �� �����ڵķ����
		{
			if(-1==pre[w])//����
			{
				pa[w] = v;//����dfs ��
				adj[v]++;

				find_cut_point(w,v);
				if(low[w] >= pre[v])//v �Ǹ��
					cut[v] = true;
				low[v] = min(low[v],low[w]);//�������ȷ�������
			}
			else//����� ���������� ��������
			{
				low[v] = min(low[v],pre[w]);
			}
		}//if ��������
	}//for
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int node,edges;
	//cin>>node>>edges;
	while(cin>>node>>edges)
	{
		if(node || edges)
		{	
			init(edges,node);
			vi_time = 0;

			//�Ӹ���ʼ dfs
			//pre[1] = low[1] = vi_time;
			find_cut_point(5,-1);//���ڵ��޸��ڵ�
			cut[5] = false;//���ڵ�Ҫ�����ж�

			if(adj[5] > 1)
				cut[5] = true;

			for(int i = 0;i < maxn;i++)
				if(cut[i])
					cout<<i<<" ";

			cout<<endl<<endl;
		}
		else
			break;
	}
	return 0;
}