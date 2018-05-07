#include <iostream>
using namespace std;

const int maxn = 1000 + 100;
bool map[maxn][maxn];
int visited[maxn];
int pre[maxn];//ƥ��߼�

int m,n;//�����Ͻڵ����

bool dfs(int i)//��x����i��� Ѱ������·��
{
	for(int j = 1;j <= n;j++)
	{
		if(!visited[j] && map[i][j])
		{
			visited[j] = true;
			if(pre[j]==0 || dfs(pre[j]))
			{
				pre[j] = i;
				return true;
			}//if pre[j]
		}
	}
	return false;//δ�ҵ�����·��
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(map,false,sizeof(map));
	int edge;
	cin>>m>>n>>edge;
	int a,b;
	for(int i = 0;i < edge;i++)
	{
		cin>>a>>b;
		map[a][b] = map[b][a] = true;
	}

	int res = 0;
	for(int i = 1;i <= m;i++)//ö��x�����е�ÿ���ڵ�
	{
		memset(visited,false,sizeof(visited));
		if(dfs(i))
			res++;
	}
	cout<<m + n - res<<endl;
	return 0;
}