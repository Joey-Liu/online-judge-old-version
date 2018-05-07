#include <iostream>
using namespace std;

const int maxn = 30;
int map[maxn][maxn];//图邻接矩阵
bool tl[maxn];//可达性矩阵，用于判断是否产生环路
bool visited[maxn];//dfs 时判断结点是否访问过
int pre[maxn];//各个结点的入度

bool topo = true;//是否需要拓扑
bool only = false;//拓扑排列是否唯一

void dfs(int n)//计算n的 可达性矩阵
{
	tl[n] = true;
	visited[n] = true;
	for(int i = 0;i < maxn;i++)
	{
		if(1==map[n][i] && visited[i]==false)
			dfs(i);
	}
}


void solve(int num,int ques)//结点和询问数量
{
	topo= true;
	only = false;
	//邻接矩阵，可达性矩阵初始化
	memset(map,0,sizeof(map));
	memset(tl,0,sizeof(tl));
	memset(pre,0,sizeof(pre));

	char ch1,ch2,c;
	int relations = 0;
	for(int i = 0;i < ques;i++)
	{
		cin>>ch1>>c>>ch2;
		int m = ch1 - 'A';
		int n = ch2 - 'A';
		map[m][n] = 1;
		pre[n]++;
		
		memset(tl,false,sizeof(tl));
		memset(visited,false,sizeof(visited));
		
		//对n 进行深搜
		dfs(n);
		//存在反向边
		if(true==tl[m])
		{
			topo = false;//不需要进行拓扑排列
			relations = i + 1;
			break;
		}

		//尝试进行拓扑排序,Q 为拓扑排序 序列
		int Q[maxn];
		memset(Q,0,sizeof(Q));
		int tot = 0;//统计ru度数为零的结点，超尾指针！！！！！！！！！！！！！
		for(int k = 0;k < num;k++)
			if(0==pre[k])
				Q[tot++] = k;

		if(tot==1)//只有一个度数为零的结点
		{
			//使用删边法
			only = true;//有可能产生唯一拓扑排序
			int count = 0;//统计每次新增 度数为1 的结点数
			while(tot < num)
			{
				count = 0;
				//注意 tot是超尾指针
				int tmpoint = Q[tot - 1];
				//使用删边法，计算拓扑序列
				for(int k = 0;k < num;k++)
				{
					if(1==map[tmpoint][k])
					{
						//count++; 失误
						pre[k]--;
						if(0==pre[k])
						{
							Q[tot++] = k;
							count++;
						}
					}
				}//for 
				//若count > 1 则 拓扑序列不唯一，不用继续删边法，同时应该将删除的边恢复  处理下一关系
				if(count > 1)
				{
					for(int i = 0;i < num;i++)
					{
						if(1==map[tmpoint][i])
							pre[i]++;
					}
					only = false;
					break;
				}
			}//while

			if(only && tot==num)//产生了唯一拓扑排序
			{
				cout<<"Sorted sequence determined after "<<i + 1<<" relations: ";
				for(int i = 0;i < num;i++)
					cout<<char('A' + Q[i]);
				cout<<"."<<endl;
				//在屏蔽掉后续输入后 ，计算下一样例
				for(int bi = 0;bi < (ques - i - 1);bi++)
					cin>>ch1>>c>>ch2;
				break;
			}
			else //没有产生唯一的拓扑排序，那么恢复删除的边
			{
				memset(pre,0,sizeof(pre));
				for(int j = 0;j < num;j++)
					for(int k = 0;k < num;k++)
						if(1==map[j][k])
							pre[k]++;
			}
		}//if 只有一个度数为一的节点
		else//有多个度数唯一的结点则处理下一关系
		{
			continue;
		}

	}//for，处理下一关系
	//存在反向边
	if(!topo)
	{
		cout<<"Inconsistency found after "<<relations<<" relations."<<endl;
		for(int i = 0;i < ques -relations;i++)
			cin>>ch1>>c>>ch2;
	}
	else if(!only)
		cout<<"Sorted sequence cannot be determined."<<endl;
}


int main()
{
	freopen("B.1.dat","r",stdin);
	freopen("out.txt","w",stdout);
	int nu,qu;
	while(cin>>nu>>qu)
	{
		if(nu || qu)
			solve(nu,qu);
		else
			break;
	}
	return 0;
}