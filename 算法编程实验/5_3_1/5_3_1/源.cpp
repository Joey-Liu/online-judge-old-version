#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 1000 + 100;
int root;
int n;//�ڵ�����
int parent[maxn];//���ڵ�
int nex[maxn];//Ⱦɫ˳��
int cnt[maxn];//������
int c[maxn];//Ⱦɫ����
int v[maxn][maxn];//�ڽӾ���

double ave[maxn];//ÿ���ڵ�ƽ��Ⱦɫ����

void init()
{
	int x,y;
	memset(v,0,sizeof(v));
	for(int i = 1;i <= n;i++)
		cin>>c[i];
	for(int i = 1;i < n;i++)
	{
		cin>>x>>y;
		v[x][++v[x][0]] = y;
		v[y][++v[y][0]] = x;
	}
}

void DFS(int x)
{
	int tmp;
	for(int i =1;i <= v[x][0];i++)
	{
		tmp = v[x][i];
		if(0==parent[tmp])
		{
			parent[tmp] = x;
			DFS(tmp);
		}
	}
}

void addedge(int x,int y)//��y����x��Ⱦɫ˳���
{
	while(nex[x])
	{
		x = nex[x];
	}
	nex[x] = y;
}

void solve()
{
	memset(parent,0,sizeof(parent));
	parent[root] = -1;
	DFS(root);//��rootΪ��������ָ��

	for(int i = 1;i <= n;i++)
	{
		ave[i] = c[i];//���ƽ��ֵ��ʼ��
		cnt[i] = 1;
	}
	bool flag[maxn];//�ڵ��Ƿ��Ѿ��������,true Ϊ��δ����
	memset(flag,true,sizeof(flag));
	memset(nex,0,sizeof(nex));
	int tmp;

	for(int count = 1;count < n;count++)//����n-1�νڵ㴦��
	{
		double maxp = 0;//wa �˺þ�
		for(int i =1;i <= n;i++)
		{
			if((flag[i]) && (ave[i] > maxp) && (i != root))//�����δ������ƽ��ֵ��,ע��i ��=root
			{
				maxp = ave[i];
				tmp = i;
			}
		}
		int fa = parent[tmp];
		addedge(fa,tmp);//��tmp����fa��˳����
		//��fa��㼰���Ͻ�����Ӱ�죬ʵ���Ͼ��ǶԻ�δ���д���Ľ��ƽ��Ⱦɫ�ʵ�Ӱ��
		while(!flag[fa])
			fa = parent[fa];

		flag[tmp] = false;
		//�Խڵ�ƽ��Ⱦɫֵ �ͺϲ��ڵ������и���
		ave[fa] = (cnt[fa] * ave[fa]  +  cnt[tmp] * ave[tmp])/(cnt[fa] + cnt[tmp]);
		cnt[fa] += cnt[tmp];

	}//for int count
	
	long long int res = 0;
	tmp = root;
	for(int i = 1;i <= n;i++)
	{
		res += i * c[tmp];
		tmp = nex[tmp];
	}
	cout<<res<<endl;
}//solve

int main()
{
	freopen("color.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>n>>root;
	while(n || root)
	{
		init();
		solve();
		cin>>n>>root;
	}
	return 0;
}