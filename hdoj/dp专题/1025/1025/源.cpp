/*   最不动脑子版本
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 500000 + 10;

int rds[maxn];	
int comp[maxn];	//作为比较数组 
int dp[2][maxn];//dp 求lcs时，只用到前一个状态 和 上一层状态 dp[1][j] 意味着当前第i个位置 与 当前第j个位置的最大公共子串 dp[0][j]为 第i-1个位置的最大公共子串
int length;

void solve()
{
	int current, previous;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= length; i++)
	{
		for (int j = 1; j <= length; j++)
		{
			if (i % 2)	//奇数次
			{
				current = 1;
				previous = 0;
			}
			else
			{
				current = 0;
				previous = 1;
			}
			if (rds[i] == comp[j])
				dp[current][j] = dp[previous][j - 1] + 1;
			else if (dp[previous][j] >= dp[current][j - 1])
				dp[current][j] = dp[previous][j];
			else
				dp[current][j] = dp[current][j - 1];
		}
	}// for int i
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum = 0;
	while (cin >> length)
	{
		int index;
		for (int i = 1; i <= length; i++)
		{
			cin >> index;
			cin >> rds[index];
			comp[i] = i;
		}

		solve();
		int res = 0;
		if (length % 2)
			res = 1;
		
		cout << "Case " << ++casenum << ":" << endl;
		cout << "My king, at most "
			<< dp[res][length];
		if (dp[res][length] == 1)
			cout << " road ";
		else
			cout << " roads ";
		cout << "can be built." << endl << endl;
	}

	return 0;
}
*/

/*
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 500000 + 10;
int rds[maxn];
int dp[maxn];
int length;

//dp法 求最长不降子序列 dp[i]表示 以i 为结尾的最长不降子序列长度 dp[i] = max(dp[j] | a[j] < a[i]) + 1
void solve()
{
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;					//边界

	for (int i = 2; i <= length; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (rds[j] < rds[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}// for int j
	}//for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int  casenum = 0;
	while (cin >> length)
	{
		int index;
		for (int i = 0; i < length; i++)
		{
			cin >> index;
			cin >> rds[index];
		}

		solve();
		int res = dp[1];
		for (int i = 1; i <= length; i++)
		{
			if (res < dp[i])
				res = dp[i];
		}

		cout << "Case " << ++casenum << ":" << endl;
		cout << "My king, at most "<< res;
		if (res == 1)
			cout << " road ";
		else
			cout << " roads ";
		cout << "can be built." << endl << endl;
	}//while cin
	return 0;
}
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int maxn = 500000 + 20;

int rds[maxn];
int B[maxn];
int length;

int BinarySearch(int num,int len)
{
	int lp = 1, rp = len;
	int mid = (lp + rp) / 2;

	while (lp + 1 < rp)
	{
		if (B[mid] < num)
			lp = mid;
		else if (B[mid] > num)
			rp = mid;
		else
			return mid;
		mid = (lp + rp) / 2;
	}
	if (B[lp] > num)
		return lp;
	return rp;
}

int solve()
{
	memset(B, 0, sizeof(B));

	B[1] = rds[1];
	int len = 1;	//len 为最终B数组长度

	for (int i = 2; i <= length; i++)
	{
		if (rds[i] > B[len])
			B[++len] = rds[i];
		else
		{
			int position = BinarySearch(rds[i],len);
			B[position] = rds[i];
		}
	}// for int i

	return len;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int  casenum = 0;
	while (scanf("%d",&length)==1)
	{
		int index;
		/*
		for (int i = 0; i < length; i++)
		{
			scanf("%d", &index);
			scanf("%d", &rds[index]);
		}
		*/
		for (int i = 1; i <= length; i++)
			scanf("%d", &rds[i]);

		int res = solve();
		//cout << "Case " << ++casenum << ":" << endl;
		printf("Case %d:\n", ++casenum);
		//cout << "My king, at most " << res;
		printf("My king, at most %d", res);
		if (res == 1)
			printf(" road ");
		else
			printf(" roads ");
		printf("can be built.\n\n");
	}//while cin
	return 0;

}