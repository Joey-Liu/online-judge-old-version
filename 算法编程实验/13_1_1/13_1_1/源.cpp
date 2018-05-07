#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 200 + 50;
struct stone
{
	double x,y;
}node[maxn];

double dis[maxn][maxn];//���ڵ�����
bool con[maxn][maxn];//�ɴ��Ծ���

void init(int n)
{
	for(int i = 0;i < n;i++)
		cin>>node[i].x>>node[i].y;

	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			dis[i][j] = sqrt(pow(node[i].x - node[j].x,2) + pow(node[i].y - node[j].y,2));
}

void solve(int num,int n)
{
	double lp = 0.0;
	double rp = 5000;
	double mid; 

	while(rp - lp >= 1e-5)
	{
		//�ȹ����ϵ����
		mid = (lp + rp)/2;
		for(int i =0;i < n;i++)
			for(int j = 0;j < n;j++)
				if(dis[i][j] <= mid)
					con[i][j] = true;
				else
					con[i][j] =	false;
		
		//����ɴ��Ծ���
		for(int k = 0;k < n;k++)
			for(int i = 0;i < n;i++)
				for(int j = 0;j < n;j++)
					con[i][j] |= con[i][k] & con[k][j];


		if(con[0][1])//��mid��Զ�������ܹ���0��1
			rp = mid;
		else
			lp = mid;
	}
	printf("Scenario #%d\n",num);
	printf("Frog Distance = %.3lf\n\n",rp);
}

int main()
{
	freopen("frogger.in","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum = 1;
	int n;
	cin>>n;
	while(n != 0)
	{
		init(n);
		solve(casenum++,n);
		cin>>n;
	}
}
