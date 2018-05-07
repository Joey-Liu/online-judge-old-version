#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int maxn = 30;
int node[maxn];//结点是否可用,1可用
int pre[maxn];//结点入度
int map[maxn][maxn];//图邻接矩阵
int N;//节点个数

void DFS(int dep,int num,string str)//num 为节点个数，dep目前输出weizhi,now为目前第几个字符(0,0,"")
{
	if(0 !=dep)
		str += (dep + 'a' -1);
	if(N ==num)
	{
		cout<<str<<endl;
		return;
	}
	for(int i = 1;i < maxn;i++)
	{
		if(node[i]==1 && 0==pre[i])//入度为零结点
		{
			node[i] = 0;
			for(int k = 1;k < maxn;k++)
			{
				if(1==map[i][k])
					pre[k]--;
			}
			DFS(i,num + 1,str);
			
			node[i] = 1;
			for(int k = 1;k < maxn;k++)
			{
				if(1==map[i][k])
					pre[k]++;
			}
		}//if
	}//for int i
}

int main()
{
	freopen("124.in","r",stdin);
	freopen("out.txt","w",stdout);
	string st;
	while(getline(cin,st))
	{
		memset(node,0,sizeof(node));//节点初始化
		memset(map,0,sizeof(map));//初始化
		memset(pre,0,sizeof(pre));//入度初始化
		N = 0;
		istringstream ss(st);
		
		char c;
		while(ss>>c)
		{
			node[c - 'a' + 1] = 1;
			N++;
		}
		getline(cin,st);
		istringstream ss2(st);
		char ch1,ch2;
		while(ss2>>ch1>>ch2)
		{
			map[ch1 - 'a' +1][ch2 - 'a' +1] = 1;
			pre[ch2 - 'a' +1]++;
		}
		
		DFS(0,0,"");
		cout<<endl;
	}//while getline
	return 0;
}