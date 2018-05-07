#include <iostream>
using namespace std;

const int maxn = 200 + 50;

int color[maxn];
int length[maxn];//����1 �洢
int after[maxn];//�����ɫ��ͬ�����ķ�������
int seq[maxn];//input
int cnum;//��ɫ��������
int dp[maxn][maxn][maxn];//�� �� i�� ����j�飬������ k����ͬɫ��ʱ��������

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum,cas = 1;
	cin>>casenum;
	while(casenum--)
	{
		int num;
		cin>>num;
		
		for(int i = 1;i <= num;i++)
			cin>>seq[i];

		///////////////������ɫ����
		cnum = 1;
		color[1] = seq[1];
		int tlen = 1;
	
		for(int i = 2;i <= num;i++)
		{
			if(seq[i -1]==seq[i])
				tlen++;
			else
			{
				color[cnum] = seq[i -1];
				length[cnum++] = tlen;
				tlen = 1;
			}
		}
		color[cnum] = seq[num];
		length[cnum] = tlen;

		//ͳ�Ƹ�����������ɼӶ��� ��ͬ����
		memset(after,0,sizeof(after));
		for(int i = 1;i < cnum;i++)
		{
			for(int j = i + 2;j <= cnum;j++)
			{
				if(color[i]==color[j])
					after[i] += length[j];
			}
		}

		memset(dp,0,sizeof(dp));
		//�Ե����� �ó��ȱ�����������ַ�������
		for(int dis = 1;dis <= cnum;dis++)
		{
			for(int lp = 1;lp + dis - 1<= cnum;lp++)
			{
				int rp = lp + dis - 1;
				for(int k = 0;k <= after[rp];k++)//ö��rp���滹��k ����ͬ�ַ�
				{
					dp[lp][rp][k] = dp[lp][rp - 1][0] + (length[rp] + k) * (length[rp] + k);
					for(int p = lp;p < rp;p++)//ö���м�ɫ��,Ӧ�ô� lp ����ʼ
						if(color[p]==color[rp])
							dp[lp][rp][k] = max(dp[lp][rp][k],dp[lp][p][k + length[rp]] + dp[p + 1][rp - 1][0]);

				}//for int k	
			}//for lp
		}//for dis

		cout<<"Case "<<cas++<<":"<<" "<<dp[1][cnum][0]<<endl;
	}//while casenum
	return 0;
}