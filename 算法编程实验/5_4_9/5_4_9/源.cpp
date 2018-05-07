#include <iostream>
using namespace std;

const int maxn = 30;

int fi[maxn];//ÿ������ʼ�ܵ�������
int	redu[maxn];//ÿ������������
int onway[maxn];//·�̺ķ�ʱ��
int finum[maxn];//ÿ������ǰ�ܵ�������
int fitime[maxn];//ÿ����ͣ��ʱ��

int restime[maxn];//���ÿ����ͣ��ʱ��,����1
int ans = 0;//����������

int time = 0;//����ʱ�� (����)
int lakenum = 0;//������

int pickmax(int arr[],int num)
{
	int tmp = 0,record = 1;//����Ҳ������ֵ���Ǿ���1 �ź�
	for(int i = 1;i <= num;i++)
	{
		if(arr[i] > tmp)
		{
			record = i;
			tmp = arr[i];
		}
	}
	return record;
}

void init()
{
	cin>>time;
	time *= 60;
	for(int i = 1;i <= lakenum;i++)
		cin>>fi[i];
	for(int i = 1;i <= lakenum;i++)
		cin>>redu[i];

	for(int i = 1;i < lakenum;i++)
		cin>>onway[i];
}


void solve()
{
	int now = 0;//����������
	ans = -1;
	int ed = 1;//ö��ÿ�ε������պ� �ı��
	for(ed = 1; ed <= lakenum;ed++)
	{
		now = 0;
		//��ʼ��,��ǰ�������� ��ͣ��ʱ��,������ʱ��
		for(int i = 1;i <= lakenum;i++)
		{
			finum[i] = fi[i];
			fitime[i] = 0;
		}
		int sum = time;
		for(int i =1;i < ed;i++)
			sum -= onway[i] * 5;

		while(sum > 0)
		{
			int tmp = pickmax(finum,ed);
			sum -= 5;
			now += finum[tmp];

			fitime[tmp] += 5;//��ǰ������ʱ��
			finum[tmp] = (finum[tmp] - redu[tmp]) > 0 ? finum[tmp] - redu[tmp] : 0;//ʣ�µ�������
		}//while sum
		
		if(now > ans)
		{
			ans = now;
			for(int i = 1;i <= lakenum;i++)
				restime[i] = fitime[i];
		}
	}//for ed
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>lakenum && lakenum != 0)
	{
		init();
		solve();
		for(int i = 1;i < lakenum;i++)
			cout<<restime[i]<<", ";
		cout<<restime[lakenum]<<endl;
		cout<<"Number of fish expected: "<<ans<<endl<<endl;
	}
}