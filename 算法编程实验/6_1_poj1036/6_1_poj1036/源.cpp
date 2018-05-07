#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 110;//��ͽ����
const int maxtime = 3000;//ʱ��
const int maxopen = 100;//�Ŵ򿪳̶�
struct men
{
	int ti;//��ͽ����ʱ��
	int pro;//��ͽ���ٶ�
	int sto;//��ͽ����
}g[maxn];

int K;//����״̬��Χ
int T;//ʱ�䷶Χ
int N;//��ͽ���� 0-N!!!!!!!!!!!!!!!!!!!!!////////////////////
int dp[maxtime][maxopen][maxn];//dp ��iʱ�� �Ŵ򿪳̶�Ϊ j ʱ ���� k ����ͽ ������ٶ�

int solve(int time,int open,int num) // 0-num����ͽ
{
	int ret = 0;
	if(dp[time][open][num] != -1)
		ret = dp[time][open][num];
	else
	{
		//�߽�����
		if(num == 0)//�������һ����ͽ
		{
			if(abs(g[N - num].sto - open) <= abs(g[N - num].ti - time))
				ret = g[N - num].pro;
		}
		else
		{
			if(abs(g[N - num].sto - open) <= abs(g[N - num].ti - time) )//���Ŀǰ��ͽN -num���Խ��뷹��
			{
				ret = max(solve(g[N -num].ti,g[N - num].sto,num - 1) + g[N - num].pro , solve(time,open,num - 1));
			}//��ͽ���Խ��뷹��
			else
				ret = solve(time,open,num - 1);
		}
	}//if dp[][][] == -1

	dp[time][open][num] = ret;
	return ret;
}

int cmp(const void* a,const void* b)
{
	men* _a = (men *)a;
	men* _b = (men *)b;
	return (_a->ti - _b->ti);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>N>>K>>T;
	N--;//N+1����ͽ
	
	for(int i = 0;i <= N;i++)
		cin>>g[i].ti;
	for(int i = 0;i <= N;i++)
		cin>>g[i].pro;
	for(int i = 0;i <= N;i++)
		cin>>g[i].sto;

	qsort(g,N + 1,sizeof(g[0]),cmp);
	memset(dp,-1,sizeof(dp));

	cout<<solve(0,0,N)<<endl;

	return 0;
}