#include <iostream>
using namespace std;

const int maxn = 100 + 10;
int map[maxn][maxn];
int dist[maxn];//��Դ�����
bool in_queue[maxn];
int queue[maxn * 50];//spfa ����
int lp,rp;//rp��β

int st;//��ʼ���
int length;
int en;//�յ�
int num;

void init()
{
	memset(map,0,sizeof(map));
	cin>>st;
	int from,to;
	cin>>from>>to;

	while(from || to)
	{
		map[from][to] = 1;
		cin>>from>>to;
	}
}

void spfa()
{
	for(int i = 0; i <= num;i++)
	{
		dist[i] = -1;
		in_queue[i] = false;
	}
	
	length = -1,en = 0;
	queue[0] = st,in_queue[st] = true;
	lp = 0,	rp = 1;
	dist[st] = 0;

	while(lp != rp)
	{
		int x = queue[lp++];
		in_queue[x] = false;

		if(dist[x] > length || dist[x]==length && x < en)
		{
			length = dist[x];
			en = x;
		}
		for(int y = 1;y <= num;y++)
		{
			if(map[x][y])//�ɳڲ���
			{
				if(dist[y] < dist[x] + 1)
				{
					dist[y] = dist[x] + 1;
					if(!in_queue[y])
					{
						queue[rp++] = y;
						in_queue[y] = true;
					}
				}
			}//if map[][]
		}
	}//while
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cnt = 1;
	while(cin>>num && num != 0)
	{
		init();
		spfa();
		cout<<"Case "<<cnt++<<": "<<"The longest path from "<<st<<" has length "<<length<<", finishing at "<<en<<".\n\n";
	}
	return 0;
}