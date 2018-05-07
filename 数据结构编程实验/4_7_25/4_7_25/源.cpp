#include <iostream>
using namespace std;

const int maxn = 200 + 50;
const int size = 6;
int result[maxn];
int caculation(int a[],int b[],int la,int lb)			//���ز��ֻ�λ��
{
	memset(result,0,sizeof(result));
	for(int i = 0;i < la;i++)
		for(int j = 0;j < lb;j++)
			result[i + j] += a[i] * b[j];
	for(int i = 0;i < la + lb;i++)
		if(result[i] >= 10)
		{
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	int i;
	for(i =0;i < la + lb;i++)
		a[i] = result[i];					//a[]���沿�ֻ�
	i--;
	return 0==a[i] ? i : i + 1;				//�����Ƿ��н�λ
}

int main()
{
	char cnum[size + 1];
	
	int count,position = 0;						//positionΪС������滹�м�λ
	while(cin>>cnum>>count)
	{
		int a[maxn],b[maxn];
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		a[0] = 1;								//a��Ų��ֻ�

		int j =0;								//b��λ��
		for(int i =size - 1;i >=0 ;i--)
		{
			if('.'==cnum[i])
			{
				position = j;
				continue;
			}
			b[j++] = cnum[i] - '0';
		}
			
		int num_count = 1;//��¼���ֻ���λ��
		for(int i = 0;i < count;i++)
			num_count = caculation(a,b,num_count,5);

		position = position * count;		//С�������Ӧ��position * countλ
		if(0==position)
		{
			for(int i = 0;i < num_count;i++)
				cout<<a[i];
			cout<<endl;
		}
		else
		{
			bool isZero = true;
			int i;
			int endposition = 0;
			for(i = num_count - 1;i >= 0;i--)
			{	
				if(0 != a[i])
					isZero = false;
				if(i >= position && isZero)
					continue;
				else if(i >= position && !isZero)
					cout<<a[i];
				else if((i + 1)==position)
				{
					for(endposition = 0;endposition < i + 1;endposition++)
						if(a[endposition] != 0)
							break;						//С��������i��endposition�Ĳ���
					break;
				}
			}
			if(!((endposition -1 )==i && 0==a[i]))
			{
				cout<<".";
				for(;i >= endposition;i--)
					cout<<a[i];
			}
			cout<<endl;
		}
	}
	system("pause");
	return 0;
}