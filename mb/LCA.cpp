#include <iostream>
#include <vector>
#include <stdio.h>
#include <memory.h>
using namespace std;

const int maxn = 1000 + 500;
bool valid[maxn];//������־
bool visited[maxn];//���ʱ�־
vector<int> c[maxn];//���ӽڵ�
vector<int> q[maxn];//ѯ��

int set[maxn];//���鼯
int ancestor[maxn];//����
int ans[maxn];//�Խ��iΪ��ͬ���ȵ�ѯ����

int set_find(int p)
{
	if(set[p] < 0)
		return p;
	return set[p] = set_find(set[p]);
}

void join(int p,int q)//p����q
{
	p = set_find(p);
	q = set_find(q);
	if(p != q)
		set[p] = q;
}

void LCA(int u)
{
	set[u] = -1;//�Ƚ��Լ��γ�һ������
	ancestor[u] = u;
	int size = c[u].size();
	for(int i =0;i < size;i++)
	{
		LCA(c[u][i]);//���ζ��ӽڵ���д���
		join(c[u][i],u);//���ӽڵ㼯�ϼ��뵽���ڼ��ϵ���
		ancestor[set_find(u)] = u;//ȷ��������ϵ����Ȳ������ı�
	}
	visited[u] = true;
	size = q[u].size();
	for(int i =0;i < size;i++)
	{
		if(visited[q[u][i]])//����Ѿ����ʹ�������i�Ľ�� ��ô�Ϳ���ֱ�ӷ��ش𰸣�����ȵ��������㱻����ʱ�ڽ��з���
		{
			ans[set_find(q[u][i])]++;//���ϵ����ȼ�Ϊ��ͬ����
		}//Ӧ��ֻ��ͳ��һ��
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num;//������
	while(1==scanf("%d",&num))
	{
		memset(valid,false,sizeof(valid));//root�ж�
		memset(visited,false,sizeof(visited));
		for(int i = 0;i < num;i++)
		{
			c[i].clear();
			q[i].clear();
			ans[i] = 0;
		}
		memset(set,-1,sizeof(set));
		memset(ancestor,-1,sizeof(ancestor));
		
		for(int i = 0;i < num;i++)
		{
			int x,y,tmp;
			scanf("%d:(%d)",&x,&y);
			for(int j = 0;j < y;j++)
			{
				scanf("%d",&tmp);
				valid[tmp -1] = true;
				c[x -1].push_back(tmp - 1);
			}
		}
		int qnum;
		scanf("%d",&qnum);
		//����ѯ��
		for(int i = 0;i < qnum;i++)
		{
			int a,b;
			char c;
			while(scanf("%c",&c) && c != '(');
			scanf("%d,%d",&a,&b);
			while(scanf("%c",&c) && c != ')');
			//�൱��ѯ������
			a--;b--;
			q[a].push_back(b);
			q[b].push_back(a);
		}
		for(int i = 0;i < num;i++)
		{
			if(!valid[i])
			{
				LCA(i);
				break;
			}
		}

		for(int i = 0;i < num;i++)
		{
			if(ans[i] > 0)
				printf("%d:%d\n",i + 1,ans[i]);
		}
	}//while
	return 0;
}