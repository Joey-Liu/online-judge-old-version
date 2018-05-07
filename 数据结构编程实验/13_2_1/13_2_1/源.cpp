#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 60;
bool map[maxn][maxn];

int p;//���ͻ���
char source,destination;

int translation(int num)//A Ϊ 1 a Ϊ 27
{
	if(num < 'a')
		return (num - 'A' + 1);
	return (num - 'a' + 27);
}
void init(int n)
{
	memset(map,false,sizeof(map));
	char c1,c2;
	for(int i =0;i < n;i++)
	{
		cin>>c1>>c2;
		int a = translation(c1);
		int b = translation(c2);
		map[a][b] = true;
		map[b][a] = true;
	}
}

int solve(int stuff,int from,int to)
{
	int g[maxn];//�����ڵ㴦��ʣ�µĻ���
	bool flag[maxn];
	
	memset(g,-1,sizeof(g));//���ڵ����������ʼΪ-1
	memset(flag,false,sizeof(flag));//�����ڵ���ڶ�����

	g[from] = stuff;

	while(true)
	{
		int next = -1;//���������·�����
		int w = 0;//�ݴ�������������

		//�ҵ������������Ľ��
		for(int i = 1;i <= maxn;i++)
		{
			if(!flag[i] && (next == -1 || w < g[i]))
			{
				next = i;
				w = g[i];
			}
		}
		
		if(-1==next)
			break;
		flag[next] = true;//�Ӷ�����ɾ��
		for(int i = 1;i < maxn;i++)//�Ը����ڵ�����������и���
		{
			if(map[next][i])
				g[i] = max( i < 27 ? w - (w - 1)/20 - 1 : w - 1,g[i]);
		}
	}//while true
	return g[to];
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum = 1;
	int n;
	while(cin>>n && n != -1)
	{
		init(n);
		cin>>p>>source>>destination;

		int so =translation(source);
		int des = translation(destination);

		int lp =1,rp = 1000000;
		while(lp + 1< rp)
		{
			int mid = (lp + rp)/2;
			int rest = solve(mid,so,des);
			if(rest >= p)
				rp = mid;
			else
				lp = mid;
		}//2 ��
		if(solve(lp,so,des)==p)
			cout<<"Case "<<casenum++<<": "<<lp<<endl;
		else
			cout<<"Case "<<casenum++<<": "<<rp<<endl;
	}
	return 0;
}