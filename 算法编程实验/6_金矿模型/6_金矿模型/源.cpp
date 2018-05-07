#include <iostream>
using namespace std;

const int max_n = 100;//�������
const int max_people = 10000;

int n;//�������
int peopletotal;//����
int peopleNeed[max_n];//��ÿ�������������
int gold[max_n];//ÿ��������ڳ��Ľ�������
int dp[max_people][max_n];//dp[i][j]��������i������ǰj�����ʱ�ܹ���õ�����������
//����-1ʱ��ʾδ֪

void init()
{
	cin>>peopletotal>>n;
	for(int i = 0;i < n;i++)
		cin>>peopleNeed[i]>>gold[i];

	for(int i = 0;i <= peopletotal;i++)
		for(int j = 0;j < n;j++)
			dp[i][j] = -1;
}

//������people���˺�ǰminenum�����ʱ�ܹ��õ�������������
int GetMaxGold(int people,int minenum)
{
	int retMaxGold;//�������Ľ�������

	if(dp[people][minenum] != -1)//˵��֮ǰ�����
		return dp[people][minenum];
	else if(0==minenum)//���ֻ�����һ�����ʱ������߽�
	{
		if(people >= peopleNeed[minenum])//���Կ���
		{
			retMaxGold = gold[minenum];
		}
		else
			retMaxGold = 0;
	}
	else if(people >= peopleNeed[minenum])//���Կ���Ŀǰ�������
	{
		retMaxGold = max( gold[minenum] + GetMaxGold(people - peopleNeed[minenum],minenum - 1),GetMaxGold(people,minenum - 1));
	}
	else
	{
		retMaxGold = GetMaxGold(people,minenum - 1);
	}

	//��¼��
	dp[people][minenum] = retMaxGold;
	return retMaxGold;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	cout<<GetMaxGold(peopletotal,n - 1);
	return 0;
}