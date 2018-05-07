#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

const int inf = 1<<20;
const int N = 30;
const int M = 1<<16;

int dp[N][M];//m״̬�� ����ռ� ��n�����ʱ����С����
int map[N][N];//map[i][j] ���i ��j �ľ���
int x[N],y[N];//���i������,���� 0,(0,0)Ϊ����������

void mmin(int & a,int b)
{
	if(a > b)
		a = b;
}

int mmax(int a,int b)
{
	if(a > b)
		return a;
	return b;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int row,col;
	while(cin>>row>>col)
	{
		int num = 0;//�������
		char ch;
		for(int i = 0;i < row;i++)
		{
			for(int j = 0;j < col;j++)
			{
				cin>>ch;
				if('L'==ch)
				{
					x[0] = i;
					y[0] = j;
				}
				else if('#'==ch)
				{
					x[++num] = i;
					y[num] = j;
				}
			}//for int j
		}//for int i
		if(0==num)
		{
			cout<<'0'<<endl;
			continue;
		}
		for(int i = 0;i <= num;i++)
			for(int j = 0;j <= num;j++)
				map[i][j] = mmax(abs(x[i] - x[j]),abs(y[i] - y[j]));//���ø�������
		int maxz = (1<<num) - 1;//���м�������ռ���״ֵ̬

		//����״̬��ʼ��
		for(int i = 0;i <= maxz;i++)
			for(int j = 0;j <= num;j++)
				dp[j][i] = inf;

		//�ռ���һ�����ʱ ����С����
		for(int i = 1;i <=num;i++)
			dp[i][1<<(i - 1)] = map[0][i];

		for(int i = 0;i <= maxz;i++)//ö������״̬
		{
			for(int j = 1;j <= num;j++)
			{
				if(0 != (i & (1<<(j - 1 ) )))//ö���ռ������һ�����j , ע�� ����Ϊ��j - 1��!!!!!!!!!!!!!!
				{
					for(int k = 1;k <= num;k++)//������ j �����ʼ ��ö�� δ�ռ��ļ�� k��������С����
					{
						if(0== (i & (1<<(k - 1))) )
							mmin(dp[k][i + (1<<(k - 1))],dp[j][i] + map[j][k]);
					}
				}

			}//for int j
		}//for int i

		int res = inf;
		for(int i = 1;i <= num;i++)
			mmin(res,dp[i][maxz] + map[0][i]);//��ȫ���ռ���״̬�� ��ö������ռ�Ϊi ����С����
		cout<<res<<endl;
	}//while cin>>
	return 0;
}