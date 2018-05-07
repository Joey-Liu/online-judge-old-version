#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 110;//��ͽ����
const int maxopen = 100;//�Ŵ򿪳̶�
struct men
{
	int ti;//��ͽ����ʱ��
	int pro;//��ͽ���ٶ�
	int sto;//��ͽ����
}g[maxn];

int K;//����״̬��Χ
int T;//ʱ�䷶Χ
int N;//��ͽ���� 
int dp[maxn];//dp[i]��i���˽��뷹��������ֵ

int cmp(const void* a,const void* b)
{
	men* _a = (men *)a;
	men* _b = (men *)b;
	return (_a->ti - _b->ti);
}

void solve()
{
	for(int i = 0;i < N;i++)
	{
		if(g[i].sto <= g[i].ti)
			dp[i] = g[i].pro;//�����ֵ��ʼ��
		else
		{
			dp[i] = 0;//����������������������ֵΪ0��
			continue;
		}

		for(int j = 0;j < i;j++)//ö�ٲ������Ž�
		{
			if(abs(g[i].ti - g[j].ti) >= abs(g[i].sto - g[j].sto) )
				dp[i] = max(dp[i],dp[j] + g[i].pro);
		}
	}//for int i
	int res = 0;
	for(int i = 0;i < N;i++)
	{
		if(res < dp[i])
			res = dp[i];
	}
	cout<<res<<endl;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>N>>K>>T;
	
	for(int i = 0;i < N;i++)
		cin>>g[i].ti;
	for(int i = 0;i < N;i++)
		cin>>g[i].pro;
	for(int i = 0;i < N;i++)
		cin>>g[i].sto;

	qsort(g,N,sizeof(g[0]),cmp);
	memset(dp,-1,sizeof(dp));
	solve();

	return 0;
}