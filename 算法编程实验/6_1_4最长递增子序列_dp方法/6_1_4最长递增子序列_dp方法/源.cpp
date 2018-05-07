#include <iostream>
using namespace std;
#define len(a) (sizeof(a) / sizeof(a[0]))

const int maxn = 100;

int LIS(int arr[],int len)
{
	int longest[maxn];
	for(int i = 0;i < len;i++)
		longest[i] = 1;

	for(int j = 1;j <len;j++)
		for(int i =0;i < j;i++)
			if(arr[j] > arr[i] && longest[j] < longest[i] + 1)
				longest[j] = longest[i] + 1;

	int max = 0;
	for(int i = 0;i < len;i++)
		if(max < longest[i])
			max = longest[i];

	return max;
}

int main()
{
	int a[] = {1,4,5,6,2,3,8};
	int ret = LIS(a,len(a));
	cout<<"max increment substring len = "<<ret<<endl;
	system("pause");
	return 0;
}