#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 10000 + 100;
int start[maxn];//���ӽڵ��� ���������еĿ�ʼλ��
int ele[maxn];//�������� ����0
int tot[maxn];//��㼰������ ��������
int child[maxn];//����������
bool fa[maxn];//���ڵ��ʾ

//���˴��˼·��Ӧ������̰��˼�룬�������С�ƶ�������Ӧ���������ƶ�������С
//�� �����ƶ���С����Ϊ �����ڵ����� - ����������
//�������1��fa ��ele 

int cnt = 0;

void init(int node_num)
{
	cnt = 0;

	memset(fa,false,sizeof(fa));
	int v;//�����
	for(int i = 0;i < node_num;i++)
	{
		cin>>v;
		cin>>tot[v];
		cin>>child[v];
		start[v] = cnt;//���ӽ���� ele���п�ʼλ��
		for(int j = 0;j < child[v];j++)
		{
			int tmp;
			cin>>tmp;
			ele[cnt++] = tmp;
			fa[tmp] = true;
		}
	}
}

int dfs(int c,bool flag)//�ӽڵ�c��ʼ�������
{
	int res = 0;
	for(int i = 0;i < child[c];i++)
		res += dfs(ele[ start[c] + i ] ,false);//���α�����������

	//ͳ���������
	int limit = child[c];
	for(int i = 0;i < limit;i++)
	{
		child[c] += child[ ele[start[c] + i] ]; //�Զ����������и���
		tot[c] += tot[ele [start[c] + i ] ];
	}

	//if(flag==false)
	res += abs(tot[c] - (child[c] + 1));
	return res;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(cin>>n && n != 0)
	{
		init(n);
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(!fa[i])
			{
				ans += dfs(i,true);
			}
		}

		cout<<ans<<endl;
	}//while
	return 0;
}