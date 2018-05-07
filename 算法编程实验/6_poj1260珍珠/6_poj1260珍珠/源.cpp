#include <iostream>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];//����������
int p[maxn];//����۸� ����1
int dp[maxn];//dp[i] �ڹ��� ��i������ʱ �����ٻ���
int casenum;
int classnum;

void init()
{
	cin>>classnum;
	for(int i = 1;i <= classnum;i++)
		cin>>a[i]>>p[i];
}

void DP()
{
	memset(dp,100,sizeof(dp));
	dp[0] = 0;

	for(int i = 1;i <= classnum;i++)
		for(int j = 1;j <= i;j++)//�ӵ�i��������ǰ j ���� i���
		{
			int tmp = 0;
			for(int k = i - j + 1;k <= i;k++)
				tmp += a[k];
			tmp = (tmp + 10 )* p[i] + dp[i - j];

			dp[i] = min(dp[i],tmp);
		}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>casenum;
	while(casenum--)
	{
		init();
		DP();
		cout<<dp[classnum]<<endl;
	}
	return 0;
}