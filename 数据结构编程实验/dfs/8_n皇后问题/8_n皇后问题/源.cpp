//�ο�����http://www.cnblogs.com/yanlingyin/archive/2011/12/19/2292041.html

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 50;
int x[maxn];//x[i] ��i���ʺ���ڵ�x[i]��λ����		�ʺ��λ�� �Ͳ��� ���ǻ��� 0��ʼ
int num;//�ʺ�����
int sum = 0;

bool place(int pos)
{
	for(int i = 0;i < pos;i++)
		if(x[i]==x[pos] || abs(x[i] - x[pos])==abs(i - pos))//������ͬһ�С��жԽ�����
			return false;
	return true;
}

void PrintMethod()			//1 ����ʺ�
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (x[i] != j)
				cout << "0";
			else
				cout << "1";
		}
		cout << endl;
	}

	cout << endl << endl;
}


//�ǵݹ�汾
void NQueen1()
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


//�ݹ�汾 level �ݹ����
void NQueen2(int level)	
{
	if (level >= num)
	{
		//PrintMethod();
		sum++;
	}
	for (int i = 0; i < num; i++)
	{
		x[level] = i;
		if (place(level))
			NQueen2(level + 1);
	}
}

int main()
{
	cout << "������ʺ�����: ";
	cin >> num;
	NQueen1();
	//NQueen2(0);
	cout << sum << endl;
	system("pause");
	return 0;
}