//˼·��������Ӿ���͵�ʱ��, ˼·��ȡ������i, j, ��������֮��ͬһ�еĶ��������γ�����һ������,
//��������������Ӷκ�,
//������������, ����������֮��߶�Ϊi - j���Ӿ��������ĺ͡�
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <memory.h>

using namespace std;
const int maxn = 100 + 20;

int size;
int mat[maxn][maxn];
int sum[maxn];			//��¼����֮�� mat[i][k]  mat[j][k]֮��ĺ�

int work(int num[])			//���� ����num������Ӵ�,û��ʹ������ ����
{
	int ans = 0, a = 0;			//a��¼֮ǰ�� �������úͣ� > 0���൱�� dp[i] = max(num[i], dp[i - 1] + num[i])
	for (int i = 0; i < size; i++)
	{
		if (a > 0)
			a += num[i];
		else
			a = num[i];
		if (a > ans)
			ans = a;
	}
	return ans;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int ans = 0,tmp = 0;
	while (cin >> size)
	{
		ans = 0, tmp = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				cin >> mat[i][j];
		}

		for (int i = 0; i < size; i++)			//��ʼ
		{
			memset(sum, 0, sizeof(sum));
			for (int j = i; j < size; j++)		//����λ��
			{
				for (int k = 0; k < size; k++)
					sum[k] += mat[j][k];
				tmp = work(sum);
				if (tmp > ans)
					ans = tmp;
			}//int j
		}//for  int i
		cout << ans << endl;
	}//while cin
	return 0;
}