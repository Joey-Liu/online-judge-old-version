#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 500 + 50;
long long int k,m,a[maxn];//m���� �� kλ���ˣ�aÿ�����ҳ��
long long int sum;//�����ҳ��
bool flag[maxn];//���ֱ���
int casenum;

void init()
{
	cin>>m>>k;
	for(int i = 1;i <= m;i++)
	{
		cin>>a[i];
		sum += a[i];
	}
}

bool judge(long long int page)
{
	memset(flag,false,sizeof(flag));
	int cnt = k;//ʣ�๤������
	long long int now = 0;
	for(int n = m;n > 0;n--)
	{
		if(now + a[n] > page || n < cnt)//�������ÿ�����˵Ĺ��������� ʣ�µ��鲻��ÿ��һ��
		{
			now = a[n];
			flag[n] = true;
			cnt--;
		}
		else
			now += a[n];
		if(cnt <= 0 && n > 0)//�����Ѿ������굫���黹��
			return false;
	}
	return true;
}

void solve()
{
	long long int lp = 0,rp = sum,mid;
	for(int i = 1;i <=m;i++)
		if(lp < a[i])
			lp = a[i];

	while(lp + 1 < rp)
	{
		mid = (lp + rp)/2;
		if(judge(mid))
			rp = mid;
		else
			lp = mid + 1;
	}
	
	if(judge(lp))
		;
	else
		judge(rp);

	for(int i = 1;i <= m;i++)
	{
		cout<<a[i];
		if(i < m)
			cout<<" ";
		if(flag[i])
			cout<<"/ ";
	}
	cout<<endl;
}

int main()
{
	freopen("books.in","r",stdin);
	freopen("out.txt","w",stdout);

	cin>>casenum;
	while(casenum--)
	{
		init();
		solve();
	}
	return 0;
}