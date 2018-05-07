#include <iostream>
using namespace std;

const int maxn = 10000 + 10;
int a[maxn];//�貽����
int e[5][5];//������������
int dp[5][5][maxn];//dp[i][j][k] ״̬Ϊi��jʱ���ӵ�k ���貽��ʼ���ķ���������

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num;
	cin>>num;

	for(int i = 1;i <= num;i++)
		cin>>a[i];
	
	for(int i = 1;i <= 4;i++)
	{
		e[i][i] = 1;
		e[0][i] = 2;
	}

	e[1][2] = e[1][4] = e[2][1] = e[2][3] = e[3][2] = e[3][4] = e[4][1] = e[4][3] = 3;
	e[1][3] = e[3][1] = e[2][4] = e[4][2] = 4;

	memset(dp,0,sizeof(dp));
	//���Ե����Ϸ��� ����dp
	for(int k = num;k >= 1;k--)
		for(int i = 0;i < 5;i++)
			for(int j = 0;j < 5;j++)
				dp[i][j][k] = min(dp[a[k] ][j][k + 1 ] + e[i][a[k]],dp[i][a[k]][k + 1] + e[j][a[k] ]);

	cout<<dp[0][0][1]<<endl;

	return 0;

}