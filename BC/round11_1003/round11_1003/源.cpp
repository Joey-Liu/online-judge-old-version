/*
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char,int> record;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int casenum;
	string str;
	int limit;
	int res = 0;

	cin>>casenum;
	while(casenum--)
	{
		record.clear();
		res = 0;
		bool flag = true;
		cin>>str>>limit;

		for(int length = 1;length <= str.size();length++)
		{
			for(int i = 0;i <= str.size() - length;i++)
			{
				flag = true;
				record.clear();
				for(int lp = i;lp <= i + length - 1;lp++)  //substring
				{
					record[str[lp]]++;
					if(record[str[lp]] > limit)
					{
						flag = false;
						break;
					}
				}///for lp
				if(flag)
					res++;
			}//for i
		}//for length
		cout<<res<<endl;
	}
	return 0;
}
*/

//״̬���� dp[i] = dp[i - 1] + i - ����i��β��������Ŀ���Ӵ�������
#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 1000;

__int64 k;
__int64 length;

char s[maxn];
int cnt[30][maxn];// cnt[i][j] �ַ�i �ڽ�βj���Ѿ����ֵĴ���
int pos[30][maxn];//pos[i][j]  ��ĸi���ִ���Ϊjʱ�� �Ӵ�λ��
int dp[maxn];//dp[i] ��βΪiʱ ������Ŀ������Ӵ�����
//flag ��Ϊ ����i��β��������Ŀ���Ӵ�������

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		int flag = 0;
		memset(cnt,0,sizeof(cnt));
		memset(pos,0,sizeof(pos));
		memset(dp,0,sizeof(dp));

		scanf("%s",s + 1);
		scanf("%d",&k);

		length = strlen(s + 1);
		for(__int64 i = 1;i <= length;i++)
		{
			__int64 id = s[i] - 'a';
			for(int j = 0;j <= 25;j++)
			{
				if(j != id)
					cnt[j][i] = cnt[j][i - 1];
				else
					cnt[j][i] = cnt[j][i - 1] + 1;
			}//for j

			pos[id][cnt[id][i]] = i;//Ŀǰ�ַ�idΪ��ô�����ʱ������
			if(cnt[id][i] > k)//���Ŀǰ���ַ��ѳ�����ĿҪ���ҵ���������ĿҪ����Ӵ�����
			{//����ȥ����1��2,3������cnt[id][i] - k�����Ӵ�����flag ֮����Ӵ�������������ֻ�а���ס֮ǰ���Ӵ����п��ܻ᲻�������飬Ҳ���ǰ���ס֮ǰ��flag���Ӵ���
				flag = max(flag,pos[id][cnt[id][i] - k]);
			}

			dp[i] = dp[i - 1] + i - flag;
		}//for int i
		printf("%d\n",dp[length]);
	}//while
	return 0;
}