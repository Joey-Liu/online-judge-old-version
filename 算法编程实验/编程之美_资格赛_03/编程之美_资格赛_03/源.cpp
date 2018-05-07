#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;
const int maxn = 10000000 + 10;

struct node
{
	int x, y;
}cu[maxn],com[maxn];//客户 通信公司坐标 

int casenum;
int ans = 0x7fffffff;
int N, M, A, B;

int cal_cu(int x,int y)
{
	int cu_ans = 0;
	for (int i = 0; i < A; i++)
	{
		cu_ans += (x - cu[i].x) * (x - cu[i].x);
		cu_ans += (y - cu[i].y) * (y - cu[i].y);
	}

	return cu_ans;
}

int cal_com(int x, int y)
{
	int com_ans = 0;
	for (int i = 0; i < B; i++)
	{
		com_ans += abs(x - com[i].x);
		com_ans += abs(y - com[i].y);
	}
	return com_ans;
}


int main()
{
	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
	cin >> casenum;
	for (int cnt = 1; cnt <= casenum; cnt++)
	{
		memset(cu, 0, sizeof(cu));
		memset(com, 0, sizeof(com));
		ans = 0x7fffffff;
		int tmp = ans;

		cin >> N >> M >> A >> B;
		for (int i = 0; i < A; i++)
			cin >> cu[i].x >> cu[i].y;
		for (int i = 0; i < B; i++)
			cin >> com[i].x >> com[i].y;

		for (int mx = 1; mx <= N; mx++)
		{
			for (int my = 1; my <= M; my++)
			{
				tmp = cal_cu(mx, my) + cal_com(mx, my);
				if (tmp < ans)
					ans = tmp;
			}//for int my
		}//for int mx

		cout << "Case #" << cnt << ": " << ans << endl;
	}
	return 0;
}
