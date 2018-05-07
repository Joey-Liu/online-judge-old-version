#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int maxn = 1000 + 100;
const int length = 15 + 10;

int desire[length];//存储总价值
int num[maxn][length];//存储各个礼物的价值,num[0]存储数字位数
int result_1[length];//保存i，j大数相加的至
int result_2[length]; //保存三个礼物相加的值
int fangan = 0;//保存结果

void add(int a[],int b[],int result[])//大数相加
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
	if(0 != result[i])//有进位产生
		result[0] = i;
	else
		result[0] = i -1;
}
void transform(char inch[],int innum[])
{
	innum[0] = strlen(inch);
	for(int i = 1;i <= innum[0];i++)//注意这里
		innum[i] = inch[ innum[0] - i] - '0';
}

int cmp(const void *_a, const void *_b)//比较大数大小
{
	int *a = (int *)_a;
	int *b = (int *)_b;
	if(a[0] < b[0])
		return -1;
	else if(a[0] > b[0])	//两数位数不同时情况
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
		return 0;//两数相同
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
		transform(total,desire);//将总价值转换

		//int kind;
		//char value[length];
		//scanf("%d",&kind);
		for(int count =0;count < kind;count++)
		{
			scanf("%s",value);
			transform(value,num[count]);//将每个礼物价值转换
		}

		qsort(num,kind,sizeof(num[0]),cmp);
		
		int i,j,mid;//二分法
		int flag = false;//边界标志
		for(i = kind - 1;i > 0;i--)
		{
			for(j = i -1;j > 0;j--)
			{
				memset(result_1,0,sizeof(result_1));///////////////相加之前把result_1至零
				add(num[i],num[j],result_1);
				int begin = 0,end = j -1;
				mid = (begin + end)/2;

				while( begin + 1 < end)//但极端情况下，begin，end可能在开始时刻就相等,或开始时就相差1
				{
					mid = (begin + end)/2;
					memset(result_2,0,sizeof(result_2));////////相加之前把result_2至零
					add(result_1,num[mid],result_2);
					if( 0 > cmp(result_2,desire))//小于总价值，取右半边
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
					else//刚刚好
						break;
				}
				//避免begin，end开始时相等但是没有进行相加操作时
				memset(result_2,0,sizeof(result_2) );
				add(result_1,num[begin],result_2);//先加上begin，若满足要求，则end = begin。
				if(0 <= cmp(result_2,desire))
				{
					end = begin;
				}
				else
				{
					memset(result_2,0,sizeof(result_2));
					add(result_1,num[mid],result_2);//还是用原来的mid
				}


				if(0 <= cmp(result_2,desire))//如果相加结果确实大于等于总价,注意可能有元素相等情况
				{
				//	while(end >=1 && 0==cmp(num[end],num[end-1]))//如果元素相等
				//		end--;
					fangan = fangan + j - end;//////////
				}
				else if( (0 > cmp(result_2,desire))  && (j==i-1 && end==j-1) )//如果相加结果没有超过总价且已经达到极限，则跳出循环
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