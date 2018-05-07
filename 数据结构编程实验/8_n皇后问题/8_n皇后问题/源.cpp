//参考博文http://www.cnblogs.com/yanlingyin/archive/2011/12/19/2292041.html

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 50;
int x[maxn];//x[i] 第i个皇后放在第x[i]个位置上
int num;//皇后数量


bool place(int pos)
{
	for(int i = 0;i < pos;i++)
		if(x[i]==x[pos] || abs(x[i] - x[pos])==abs(i - pos))//不能在同一行、列对角线上
			return false;
	return true;
}

void NQueen1(int n)
{
	int level = 0;
	x[level] = -1;

	while(level >= 0)
	{
		x[level]++;
		while(x[level] < num && (!place(level)) )
			x[level]++;							//若当前行不满足题意，则进行调整
		if(x[level] < num)//方案目前可以试试
		{
			if(level < num - 1)
			{
				level++;
				x[level] = -1;
			}
			else//输出产生的方案
			{
				for(int i = 0;i < num;i++)
					cout<<x[i]<<" ";
				cout<<endl;
			}
		}//if x[level]
		else                         //目前方案有问题，不能产生解，则进行回溯
		{
			level--;//回溯到上一个节点
		}
	}//while
}


