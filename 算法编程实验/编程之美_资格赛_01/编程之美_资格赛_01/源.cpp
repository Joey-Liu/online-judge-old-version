#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

int casenum;
const string months[] = { "", "January", "February", "March", "April",
"May", "June", "July", "August", "September", "October", "November", "December" };

const int LY = 24 + 24 + 24 + 25;

char ch, str[20];
int cnt = 0,ans = 0;
int m[3];
int y[3];
int d[3];

map<string, int> month;
typedef pair<string, int> Pair;

inline bool isLeap(int year)//���귵��true
{
	if (0 == year % 100)
		return 0 == year % 400 ? true : false;
	else
		return 0 == year % 4 ? true : false;
}

void init()
{
	month.clear();
	for (int i = 1; i <= 12; i++)
		month.insert(Pair(months[i], i));
}

//��� ��ʼ ��ĩβ ����ʱ���
bool check_st(int year, int mon, int day)
{
	if (isLeap(year))
	{
		if (mon < 2 || (2 == mon && day <= 29))
			return true;
	}
	return false;
}

bool check_en(int year, int mon, int day)
{
	if (isLeap(year))
	{
		if (mon > 2 || (2 == mon && day >= 29))
			return true;
	}
	return false;
}

//y1 Ϊ��ʼ����
//void solve(int y1, int y2)
//{
//	if (y1 + 110 > y2)
//	{
//		while (y1 <= y2)
//		{
//			if (isLeap(y1))
//				ans++;
//			y1 += 4;
//		}
//	}//if y1 + 100
//	else
//	{
//		int yy1 = (y1 / 100) * 100 + 100;
//		ans = ans + (yy1 - y1) / 4;			//��ʱ ans ����yy1 �����꣬ yy1 hundred year
//
//		int yy2 = (y2 / 100) * 100;
//		ans = ans + (y2 - yy2) / 4;			// ��ʱ ans ����yy2 ������   yy2 hundred year
//		
//		if (isLeap(yy1))
//			ans++;
//		else
//		{
//			while (true)
//			{
//				yy1 += 100;
//				if (0 == yy1 % 400)
//				{
//					ans = ans + 25;
//					break;
//				}
//				else
//					ans = ans + 24;
//			}//while
//		}//else
//
//		yy1 ��ʱΪ��������
//		
//		int t1 = (yy2 - yy1) / 400;
//		ans = ans + t1 * LY;
//
//		yy1 = yy1 + t1 * 400;
//		while (yy1 < yy2)
//		{
//			yy1 += 100;
//			if (0 != yy1 % 400)
//				ans += 24;
//			else
//				ans += 25;
//		}
//	}//else
//}


void solve(int y1, int y2)
{
	ans = (y2 >> 2) - (y1 >> 2);
	ans = ans - (y2 / 100 - y1 / 100);
	ans += (y2 / 400 - y1 / 400);
}

int main()
{
	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
	init();
	scanf("%d", &casenum);
	while (casenum--)
	{
		ans = 0;
		for (int i = 1; i <= 2; i++)
		{
			scanf("%s", str);
			m[i] = month[str];
			
			scanf("%d", &d[i]);
			scanf("%c", &ch);
			scanf("%d", &y[i]);
		}

		//if (check_st(y[1], m[1], d[1]))		
		//	ans++;						//����������
		//if (y[1] == y[2])
		//{
		//	//��һ�껹û�� 2.29
		//	if ((m[2] < 2 || (m[2] == 2 && d[2] < 29)) && ans != 0)
		//		ans = 0;
		//	else if ((m[2] > 2 || (m[2] == 2 && d[2] >= 29) ) && ans != 0)			//ͬһ�� һ��2.29
		//		ans = 1;
		//	else
		//		ans = 0;
		//}
		//else//��ͬ��
		//{
		//	if (check_en(y[2], m[2], d[2]))
		//		ans++;
		//}

		//�뷨:���� ��ʼ��ݣ�����ֹ���

		if (1 == m[1] || (2 == m[1] && d[1] <= 29) )	//��ʼ��� ����2.29
			y[1]--;
		if (1 == m[2] || (2 == m[2] && d[2] < 29))
			y[2]--;

		if (y[1] <= y[2])
			solve(y[1], y[2]);
		printf("Case #%d: %d\n", ++cnt, ans);
	}// while casenum--;
	return 0;
}
