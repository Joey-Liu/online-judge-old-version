#include <iostream>
using namespace std;

const int maxn = 40 + 10;
int row,col;
bool map[maxn][maxn];
//bool flag = false;//�Ƿ��ҵ�����
int step = 1;
int sr,sc;
int er,ec;

int dr[4] = {0,-1,0,1};
int dc[4] = {-1,0,1,0};
int dis[maxn][maxn];

bool in_range(int ro,int co)
{
	if(ro >= 1 && ro <= row && co >= 1 && co <= col && map[ro][co])
		return true;
	return false;
}


void init()
{
	memset(map,true,sizeof(map));
	memset(dis,100,sizeof(dis));

	char ch;
	cin>>col>>row;
	for(int i = 1;i <= row;i++)
	{
		for(int j = 1;j <= col;j++)
		{
			cin>>ch;
			if('#'==ch)
				map[i][j] = false;
			else if('S'==ch)
			{
				sr = i;
				sc = j;
			}//for int j
			else if('E'==ch)
			{
				er = i;
				ec = j;
			}
		}//for int j
	}
	step = 0;
}


int dfs_left(int ro,int co,int t)//t Ϊ��ǰλ�÷���
{
	if(!map[ro][co] || !in_range(ro,co))
		return 2;
	
	bool flag = false;
	step++;
	if(ro==er && co==ec)//�����յ�
		return 1;
	
	int tt = (t + 3) % 4;//��ʱ����ת90,(������)
	for(int i = 0;i < 4;i++)
	{
		int res = dfs_left(ro + dr[tt],co + dc[tt],tt);
		if(1==res)
		{
			flag = true;
			break;
		}
		else if(0==res)//û���ҵ��յ㣬���غ󻻸�����
		{
			step++;
			tt = (tt + 1) % 4;
		}
		else
			tt = (tt + 1) % 4;
	}
	return flag;
}


int dfs_right(int ro,int co,int t)//t Ϊ��ǰλ�÷���
{
	if(!map[ro][co] || !in_range(ro,co))
		return 2;
	
	bool flag = false;
	step++;
	if(ro==er && co==ec)//�����յ�
		return 1;
	
	int tt = (t + 1) % 4;//˳ʱ����ת90,(������)
	for(int i = 0;i < 4;i++)
	{
		int res = dfs_right(ro + dr[tt],co + dc[tt],tt);
		if(1==res)
		{
			flag = true;
			break;
		}
		else if(0==res)//û���ҵ��յ㣬���غ󻻸�����
		{
			step++;
			tt = (tt + 3) % 4;
		}
		else
			tt = (tt + 3) % 4;
	}
	return flag;
}


void dfs(int ro,int co,int k)//��k���ߵ� �ýڵ�
{
	if(!in_range(ro,co) || !map[ro][co] || k >= dis[ro][co])//�����ǽ ���������ʹ�
		return;

	dis[ro][co] = k;
	if(ro==er && co==ec)
	{
		step = k;
		return;
	}

	for(int i = 0;i < 4;i++)
	{
		dfs(ro + dr[i],co + dc[i],k + 1);
	}
}

int main()
{
	freopen("7.in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		init();
		
		dfs_left(sr,sc,0);
		cout<<step<<" ";
		step = 0;

		dfs_right(sr,sc,0);
		cout<<step<<" ";
		step = 0;
		

		dfs(sr,sc,1);
		cout<<step<<endl;
	}
	return 0;
}