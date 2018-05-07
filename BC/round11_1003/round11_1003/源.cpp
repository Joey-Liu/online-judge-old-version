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

//状态方程 dp[i] = dp[i - 1] + i - （以i结尾不满足题目的子串数量）
#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 1000;

__int64 k;
__int64 length;

char s[maxn];
int cnt[30][maxn];// cnt[i][j] 字符i 在结尾j处已经出现的次数
int pos[30][maxn];//pos[i][j]  字母i出现次数为j时的 子串位置
int dp[maxn];//dp[i] 结尾为i时 满足题目的最大子串数量
//flag 即为 （以i结尾不满足题目的子串数量）

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

			pos[id][cnt[id][i]] = i;//目前字符id为这么多个的时候在哪
			if(cnt[id][i] > k)//如果目前的字符已超过题目要求，找到不满足题目要求的子串个数
			{//（减去超出1，2,3。。。cnt[id][i] - k个的子串，而flag 之后的子串均满足条件，只有包含住之前的子串才有可能会不满足提议，也就是包含住之前的flag个子串）
				flag = max(flag,pos[id][cnt[id][i] - k]);
			}

			dp[i] = dp[i - 1] + i - flag;
		}//for int i
		printf("%d\n",dp[length]);
	}//while
	return 0;
}