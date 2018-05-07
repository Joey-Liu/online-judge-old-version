#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 50;
struct judgement
{
	int c,p,t,r;
};

struct team
{
	int id,ac,t;
	int p[25];
	bool sol[25];
};

bool cmp_t(const judgement &a,const judgement &b)
{
	return a.t < b.t;
}

bool cmp_ac(const team &a,const team &b)
{
	if(a.ac != b.ac)
		return a.ac > b.ac;
	else if(a.t != b.t)
		return a.t < b.t;
	else
		return a.id < b.id;
}

judgement a[maxn];					//�ύ����
team t[maxn];						//��������
int n=0,m=0;						//�����������ύ��

int main()
{
	memset(a,0,sizeof(a));
	memset(t,0,sizeof(t));
	cin>>n>>m;
	for(int i=1;i <= m;i++)
		cin>>a[i].c>>a[i].p>>a[i].t>>a[i].r;
	for(int i=1;i <= n;i++)
		t[i].id = i;
	sort(a + 1,a + m + 1,cmp_t);			//�Ƚ��ύ��Ϣ����
	for(int i = 1;i <= m;i++)               //��ʱ�䴦����Ϣ
	{
		int x =a[i].c;						//�Ӻ�
		int y =a[i].p;						//��Ŀ��
		if(t[x].sol[y])
			continue;						//�����ظ�����
		if(a[i].r)
		{
			t[x].ac++;
			t[x].sol[y]=true;
			t[x].t += 1200 * t[x].p[y] + a[i].t;
		}
		t[x].p[y]++;
	}
	sort(t+1,t + n +1,cmp_ac);
	for(int i =1;i < n;i++)
		cout<<t[i].id<<' ';
	cout<<t[n].id<<endl;
	system("pause");
	return 0;
}
