#include <iostream>
using namespace std;

const int maxn = 100 + 50;
int meet[maxn][maxn];//-1 ��δ��ȷ��0 ������ 1 ����
int bmat[maxn][maxn];//��������,��Ż���1
int st[maxn];//���������

int n;//����
int seva = 0;//��������
bool men[maxn];//������ʶ
int casenum;

void init()
{
	cin>>n;
	char ch;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
		{
			cin>>ch;
			bmat[i][j] = ch - '0';
		}
}

int dp(int i,int j)//i,j�Ƿ������� ,i ,j Ϊ�����б��
{
	if(-1 != meet[i][j])
		return meet[i][j];
	else
	{   
		bool flag = false;
		int k = i +1;
		for(k = i + 1;k < j;k++)
		{
			if(dp(i,k) && dp(k,j) && (bmat[st[i] ][st[k] ] || bmat[st[j] ][st[k] ]))
			{
				flag = true;
				break;
			}
		}
		if( true==flag)
			return 	(meet[i][j] = 1);
		else
			return (meet[i][j] = 0);
	}
}

//��meet�����¸�һ��Ӧ�þͺ�
void solve()
{
	seva = 0;
	for(int i = 1;i <= n;i++)//ö��ÿ�����
	{
		memset(meet,-1,sizeof(meet));
		int num = 1;//�����б��
		for(int j = i;j <= n;j++)
			st[num++] = j;
		for(int j = 1;j < i;j++)
			st[num++] = j;
		st[num] = i;

		for(int j = 1;j <= n;j++)
			meet[j][j +1] = 1;

		if(1==dp(1,num))
		{
			seva++;
			men[i] = true;
		}
	}
	cout<<seva<<endl;
	for(int i = 1;i <= n;i++)
		if(men[i])
			cout<<i<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>casenum;
	while(casenum--)
	{
		init();
		solve();
	}
	return 0;
}