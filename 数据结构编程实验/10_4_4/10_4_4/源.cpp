#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 3000000;
int heap[maxn];//ԭ����
int afr[maxn];//�����������
int layer;
int num;//�ڵ�����

void init()
{
	cin>>layer;
	num = pow((double)2,(double)layer) - 1;
	for(int i = 1;i <= num;i++)
		cin>>heap[i];
}

int index = 1;//�����������

void dfs(int n)//
{
	if(n * 2 <= num)//�����
		dfs(n * 2);
	if(n * 2 + 1 <= num)//�Ҷ���
		dfs(n * 2 + 1);
	afr[index++] = heap[n];
}

int len;//�����������
int B[maxn];

int BiSearch(int num)
{
	int lp = 0;
	int rp = len - 1;
	int mid = (lp + rp)/2;
	while(lp + 1 < rp)
	{
		if(B[mid] < num)
			lp = mid;
		else if(B[mid] > num)
			rp = mid;
		else
			return mid;
		mid = (lp +rp)/2;
	}
	if(B[lp] > num)
		return lp;
	else
		return rp;
}

int LIS(int n)
{
	len = 1;
	B[0] = afr[0];
	int i,pos = 0;

	for(i = 1;i < n;i++)
	{
		if(afr[i] > B[len - 1] + 1)///////////////////////////////////
		{
			B[len] = afr[i];
			len++;
		}
		else
		{
			pos = BiSearch(afr[i]);
			B[pos] = afr[i];
		}
	}//for int i
	return len;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	dfs(1);
	cout<<num - LIS(num)<<endl;
	return 0;
	
}