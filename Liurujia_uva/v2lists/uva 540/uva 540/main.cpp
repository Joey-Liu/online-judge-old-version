#include <iostream>
#include <string>
using namespace std;
const int maxp = 1000000;				//Ԫ�����
const int maxt = 1000;					//������Ŀ
const int maxn = 200000 + 10;			//Ԫ�ع�ģ

struct node
{
	int p;						//Ԫ�����
	int pre, next;				//Ԫ��ǰ�������
}r[maxn];
int used;				//��Ԫ���±�
int belong[maxp];		//Ԫ�������ŶӺ�
int pos[maxt];			//���������һ��Ԫ������λ��
int st, ed;				//���ף���βָ��

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
				belong[x] = i;				//�õ�Ԫ�����ڶ���
			}
			pos[i] = -1;					//��ʱ������û��Ԫ��
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
				int s = pos[belong[x]];				//�Ŷ������һ��Ԫ��
				if (s < 0)							//������û���Ŷ�Ԫ��
				{
					r[used].pre = ed;
					r[used].next = -1;				//ע�⣬��ʱû������Ԫ��������棬���Ԫ����Ϊ-1
					if (ed >= 0)					//˵����������Ԫ��
					{
						r[ed].next = used;
					}
					else if (st < 0)				//������û��Ԫ��
					{
						st = used;
					}
					ed = used;
				}
				else                           //���������Ŷ�Ԫ��
				{
					r[used].pre = s;
					//	r[s].next = used;			�����ˣ����ִ��󶼷���
					r[used].next = r[s].next;
					r[s].next = used;
					if (s == ed)					//���sΪ���һ��Ԫ�أ���û�к�̣�
						ed = used;

					if (r[s].next >= 0)		//���s�к��Ԫ��
						r[r[s].next].pre = used;
				}
				pos[belong[x]] = used++;			//�Ŷ������һ��Ԫ��λ�ø��£�used����
			}
			else if ("DEQUEUE" == str)
			{
				cout << r[st].p << endl;			//���������Ԫ��
				if (st == pos[belong[r[st].p]])			//�Ŷ���Ψһ�ڶ����е�Ԫ�س���
					pos[belong[r[st].p]] = -1;
				st = r[st].next;				//���׸���
			}
			cin >> str;
		}
		cout << endl;
		cin >> t;
	}
	system("pause");
	return 0;
}