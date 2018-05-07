#include <iostream>
#define inf 0x3f3f3f3f

using namespace std;
const int maxn = 300 + 20;
int lx[maxn],ly[maxn];//��㶥��
int pre[maxn];//���ǰ��
int slack[maxn];//��� �������Ȩ ��С��ֵ
bool visx[maxn],visy[maxn];
int map[maxn][maxn];
int num;//���� ��������

bool dfs(int i)//Ѱ�ҿ��б�
{
	visx[i] = true;
	for(int j = 1;j <= num;j++)
	{
		if(visy[j])
			continue;
		
		int t = lx[i] + ly[j] - map[i][j];
		if(0==t)//���б�
		{
			slack[j] = 0;
			visy[j] = true;//��������Ӧ��Ҳ����
			if(pre[j]==0 || dfs(pre[j]))
			{
				pre[j] = i;
				return true;
			}
		}
		else
			slack[j] = min(slack[j],t);
	}//for int j
	return false;
}

int KM()
{
	memset(pre,0,sizeof(pre));
	memset(ly,0,sizeof(ly));
	memset(lx,0,sizeof(lx));

	for(int i = 1;i <= num;i++)
		for(int j = 1;j <= num;j++)
			if(map[i][j] > lx[i])
				lx[i] = map[i][j];

	for(int x = 1;x <= num;x++)//��ÿһ��x ���������·�����ӿ��б�
	{
		for(int i = 1;i <= num;i++)
			slack[i] = inf;
		while(true)
		{
			memset(visx,false,sizeof(visx));
			memset(visy,false,sizeof(visy));

			if(dfs(x))
				break;

			//���� ������� d �������d 
			int d = inf;
			for(int i = 1;i <= num;i++)
				if(!visy[i] && d > slack[i])
					d = slack[i];

			for(int i = 1;i <= num;i++)
				if(visx[i])
					lx[i] -= d;

			for(int i = 1;i <= num;i++)
				if(visy[i])//			���i��������·���� ���� visx[i] �Ѿ���ȥ d ��Ҫ���� slackֵ
					ly[i] += d;
				else
					slack[i] -= d;

		}
	}//for int x
	int ans = 0;
	for(int i = 1;i <= num;i++)
		if(pre[i] != 0)
			ans += map[pre[i]][i];

	return ans;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>num)
	{
		for(int i = 1;i <= num;i++)
			for(int j = 1;j <= num;j++)
				cin>>map[i][j];

		cout<<KM()<<endl;
	}
	return 0;
}