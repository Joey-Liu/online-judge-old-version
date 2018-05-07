#include <iostream>
using namespace std;

const int maxn = 100 + 10;
int map[maxn][maxn];
int has[maxn];//ͼ�н����ڱ�ʶ
int pre[maxn];
int queue[maxn];//�����������
int tot;//��������ָ��

void init(int num,int qua)
{
	memset(map,0,sizeof(map));
	memset(pre,0,sizeof(pre));
	memset(queue,0,sizeof(queue));
	tot = 0;
	int m,n;
	for(int i = 0;i < qua;i++)
	{
		cin>>m>>n;
		map[m][n] = 1;
		pre[n]++;
	}
	memset(has,true,sizeof(has));
}

void Kahn(int num)
{
	for(int i = 1;i <= num;i++)
	{
		if(0==pre[i])
			queue[tot++] = i;
	}

	;
	for(int i = 0;i < tot;i++)
	{
		cout<<queue[i]<<" ";
		for(int j = 1;j <= num;j++)//ɾ�������ı�
		{
			if(1==map[queue[i]][j])
			{
				pre[j]--;
				if(0==pre[j])
					queue[tot++] = j;
			}
		}//for int j
	}//for int i
	cout<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	while(n || m)
	{
		init(n,m);
		Kahn(n);
		cin>>n>>m;
	}
	return 0;
}