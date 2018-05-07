#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int maxn = 1000 + 100;
const int length = 15 + 10;

int desire[length];//�洢�ܼ�ֵ
int num[maxn][length];//�洢��������ļ�ֵ,num[0]�洢����λ��
int result_1[length];//����i��j������ӵ���
int result_2[length]; //��������������ӵ�ֵ
int fangan = 0;//������

void add(int a[],int b[],int result[])//�������
{
	memset(result,0,sizeof(result));
	int i;
	for(i = 1;i <= (a[0] > b[0] ? a[0] : b[0]);i++)
	{
		result[i] = a[i] + b[i];
		if(result[i] > 9)
		{
			result[i] -= 10;
			result[i + 1]++;
		}
	}
	if(0 != result[i])//�н�λ����
		result[0] = i;
	else
		result[0] = i -1;
}
void transform(char inch[],int innum[])
{
	innum[0] = strlen(inch);
	for(int i = 1;i <= innum[0];i++)//ע������
		innum[i] = inch[ innum[0] - i] - '0';
}

int cmp(const void *_a, const void *_b)//�Ƚϴ�����С
{
	int *a = (int *)_a;
	int *b = (int *)_b;
	if(a[0] < b[0])
		return -1;
	else if(a[0] > b[0])	//����λ����ͬʱ���
		return 1;
	else
	{
		for(int i = a[0];i >= 1;i--)
		{
			if(a[i] - b[i] > 0)
				return 1;
			else if(a[i] - b[i] < 0)
				return -1;
		}
		return 0;//������ͬ
	}
}
using namespace std;

int main()
{
	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		int kind;
		char value[length];
		scanf("%d",&kind);
		
		char total[length];
		scanf("%s",total);
		transform(total,desire);//���ܼ�ֵת��

		//int kind;
		//char value[length];
		//scanf("%d",&kind);
		for(int count =0;count < kind;count++)
		{
			scanf("%s",value);
			transform(value,num[count]);//��ÿ�������ֵת��
		}

		qsort(num,kind,sizeof(num[0]),cmp);
		
		int i,j,mid;//���ַ�
		int flag = false;//�߽��־
		for(i = kind - 1;i > 0;i--)
		{
			for(j = i -1;j > 0;j--)
			{
				memset(result_1,0,sizeof(result_1));///////////////���֮ǰ��result_1����
				add(num[i],num[j],result_1);
				int begin = 0,end = j -1;
				mid = (begin + end)/2;

				while( begin + 1 < end)//����������£�begin��end�����ڿ�ʼʱ�̾����,��ʼʱ�����1
				{
					mid = (begin + end)/2;
					memset(result_2,0,sizeof(result_2));////////���֮ǰ��result_2����
					add(result_1,num[mid],result_2);
					if( 0 > cmp(result_2,desire))//С���ܼ�ֵ��ȡ�Ұ��
					{
						begin = mid;
						if(begin==end)
							break;
					}
					else if(0 < cmp(result_2,desire))
					{
						end = mid;
						if(begin==end)
							break;					
					}
					else//�ոպ�
						break;
				}
				//����begin��end��ʼʱ��ȵ���û�н�����Ӳ���ʱ
				memset(result_2,0,sizeof(result_2) );
				add(result_1,num[begin],result_2);//�ȼ���begin��������Ҫ����end = begin��
				if(0 <= cmp(result_2,desire))
				{
					end = begin;
				}
				else
				{
					memset(result_2,0,sizeof(result_2));
					add(result_1,num[mid],result_2);//������ԭ����mid
				}


				if(0 <= cmp(result_2,desire))//�����ӽ��ȷʵ���ڵ����ܼ�,ע�������Ԫ��������
				{
				//	while(end >=1 && 0==cmp(num[end],num[end-1]))//���Ԫ�����
				//		end--;
					fangan = fangan + j - end;//////////
				}
				else if( (0 > cmp(result_2,desire))  && (j==i-1 && end==j-1) )//�����ӽ��û�г����ܼ����Ѿ��ﵽ���ޣ�������ѭ��
				{
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}
		printf("%d\n",fangan);
		fangan = 0;
	}//while
	return 0;
}