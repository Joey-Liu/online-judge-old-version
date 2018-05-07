#include <iostream>
#include <string>
using namespace std;
const int maxp = 1000000;				//元素序号
const int maxt = 1000;					//队列数目
const int maxn = 200000 + 10;			//元素规模

struct node
{
	int p;						//元素序号
	int pre, next;				//元素前驱，后继
}r[maxn];
int used;				//新元素下标
int belong[maxp];		//元素所在团队号
int pos[maxt];			//队列中最后一个元素所在位置
int st, ed;				//队首，队尾指针

int main()
{
	freopen("team.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, loop = 0;
	cin >> t;
	while (t)
	{
		for (int i = 0; i < t; i++)
		{
			int m;
			cin >> m;
			for (int j = 0; j < m; j++)
			{
				int x;
				cin >> x;
				belong[x] = i;				//得到元素所在队列
			}
			pos[i] = -1;					//此时队列中没有元素
		}

		used = 0;
		st = ed = -1;							//

		printf("Scenario #%d\n", ++loop);
		string str;
		cin >> str;
		while ("STOP" != str)
		{
			if ("ENQUEUE" == str)
			{
				int x;
				cin >> x;
				r[used].p = x;
				int s = pos[belong[x]];				//团队中最后一个元素
				if (s < 0)							//队列中没有团队元素
				{
					r[used].pre = ed;
					r[used].next = -1;				//注意，此时没有其他元素在其后面，后继元素设为-1
					if (ed >= 0)					//说明队列中有元素
					{
						r[ed].next = used;
					}
					else if (st < 0)				//队列中没有元素
					{
						st = used;
					}
					ed = used;
				}
				else                           //队列中有团队元素
				{
					r[used].pre = s;
					//	r[s].next = used;			无语了，这种错误都犯了
					r[used].next = r[s].next;
					r[s].next = used;
					if (s == ed)					//如果s为最后一个元素（既没有后继）
						ed = used;

					if (r[s].next >= 0)		//如果s有后继元素
						r[r[s].next].pre = used;
				}
				pos[belong[x]] = used++;			//团队中最后一个元素位置更新，used更新
			}
			else if ("DEQUEUE" == str)
			{
				cout << r[st].p << endl;			//输出队列首元素
				if (st == pos[belong[r[st].p]])			//团队中唯一在队列中的元素出队
					pos[belong[r[st].p]] = -1;
				st = r[st].next;				//队首更新
			}
			cin >> str;
		}
		cout << endl;
		cin >> t;
	}
	system("pause");
	return 0;
}