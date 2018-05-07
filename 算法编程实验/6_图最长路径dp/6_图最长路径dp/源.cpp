#include <iostream>
using namespace std;

const int maxn = 100;
int map[maxn][maxn];
int pre[maxn];//���
bool has[maxn];//�Ƿ�����
int order[maxn];//��������

int edge_num;//�ߵ�����
int node_num;

int dp[maxn];//dp[i] ��Դ�ڵ� ��i�ڵ�� �·������
int parent[maxn];//�ڵ�i��ǰ���ڵ�

void init()
{
	int one,two,weight;
	memset(pre,0,sizeof(pre));
	memset(map,0,sizeof(map));

	for(int i = 0;i < edge_num;i++)
	{
		cin>>one>>two>>weight;
		map[one][two] = weight;
		pre[two]++;
	}
	memset(has,false,sizeof(has));
	memset(dp,-1,sizeof(dp));

}


void topo(int dep)//�״ε���ʱdep = 1 order[1---node_num]
{
	for(int i = 1;i < maxn && dep <= node_num;i++)
	{
		if(!has[i] && pre[i]==0)
		{
			has[i] = true;
			order[dep] = i;
			for(int k = 1;k < maxn;k++)
			{
				if(map[i][k] != 0)
					pre[k]--;
			}
			dep++;
			i = 0;
			if(dep > node_num)
				break;
		}
	}
}

void solve()
{
	memset(parent,0,sizeof(parent));
	memset(dp,0,sizeof(dp));

	for(int i = 1;i <= node_num;i++)//�Ե���������������
	{
		for(int j = 1;j < maxn;j++)
		{
			if(map[j][order[i]])
			{
				if(dp[order[i]] < dp[j] + map[j][order[i]])
				{
					dp[order[i]] = dp[j] + map[j][order[i]];
					parent[order[i]] = j;
				}
			}
		}//for int j
	}//for int i
}

void print(int n)
{
	if(parent[n] != 0)
		print(parent[n]);
	cout<<n<<" ";
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int goal;
	while(cin>>node_num>>edge_num)
	{
		init();
		topo(1);
		solve();
		cin>>goal;
		print(goal);
		cout<<endl;
	}
	return 0;
}