//�ο�����http://www.cnblogs.com/yanlingyin/archive/2011/12/19/2292041.html

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 50;
int x[maxn];//x[i] ��i���ʺ���ڵ�x[i]��λ����
int num;//�ʺ�����


bool place(int pos)
{
	for(int i = 0;i < pos;i++)
		if(x[i]==x[pos] || abs(x[i] - x[pos])==abs(i - pos))//������ͬһ�С��жԽ�����
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
			x[level]++;							//����ǰ�в��������⣬����е���
		if(x[level] < num)//����Ŀǰ��������
		{
			if(level < num - 1)
			{
				level++;
				x[level] = -1;
			}
			else//��������ķ���
			{
				for(int i = 0;i < num;i++)
					cout<<x[i]<<" ";
				cout<<endl;
			}
		}//if x[level]
		else                         //Ŀǰ���������⣬���ܲ����⣬����л���
		{
			level--;//���ݵ���һ���ڵ�
		}
	}//while
}


