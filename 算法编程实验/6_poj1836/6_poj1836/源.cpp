#include <iostream>
using namespace std;

const int maxn = 1000 + 10;
double height[maxn];
int num;
int longest1[maxn];
int longest2[maxn];

void init()
{
	cin>>num;
	for(int i = 1;i <= num;i++)
		cin>>height[i];
}

int LIS(double arr[],int len,int longest[])
{
	for(int i = 1;i <= len;i++)
		longest[i] = 1;

	for(int j = 2;j <= len;j++)
		for(int i = 1;i < j;i++)
			if(arr[j] > arr[i] && longest[j] < longest[i] + 1)
				longest[j] = longest[i] + 1;

	int tmax = 0;
	for(int i = 1;i <= len;i++)
		if(tmax < longest[i])
			tmax = longest[i];

	return tmax;
}

int LDS(double arr[],int len,int longest[])
{
	for(int i = 1;i <= len;i++)
		longest[i] = 1;

	for(int j = len - 1;j >=  1;j--)
		for(int i = j + 1;i <= num;i++)
			if(arr[j] > arr[i] && longest[j] < longest[i] + 1)
				longest[j] = longest[i] + 1;

	int tmax = 0;
	for(int i = 1;i <= len;i++)
		if(tmax < longest[i])
			tmax = longest[i];

	return tmax;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	init();
	LIS(height,num,longest1);
	LDS(height,num,longest2);

	////讨论中 题目的一种答案可以是这样的：3 4 5 1 2 5 4 3 可把中间的 1 2删除
	int tmp = 0;
	for(int i = 1;i <= num;i++)
		for(int j = i + 1;j <= num;j++)
		{
			if(longest1[i] + longest2[j] > tmp)
				tmp = longest1[i] + longest2[j];
		}
	
	cout<<(num - tmp)<<endl;
	return 0;
}