//dp[i]代表 以num[i]为结尾的子串的 最长递增子序列 长度
//dp[i] = {max(dp[j] + 1) ,j < i 且 arr[j] < arr[i]}

#include <iostream>
using namespace std;

#define len(a) (sizeof(a) / sizeof(a[0]))
const int maxn = 100;

int lis(int arr[], int len)
{
	int longest[maxn];
	for (int i = 0; i < maxn; i++)
		longest[i] = 1;

	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && longest[i] < longest[j] + 1)
				longest[i] = longest[j] + 1;
		}
	}//for int i

	int max = 0;
	for (int i = 0; i < len; i++)
	{
		if (max < longest[i])
			max = longest[i];
	}

	return max;
}

int main()
{
	int arr[] = { 5,6,7,1,2,8}; //测试数组  
	int ret = lis(arr, len(arr));
	cout << "max increment substring len=" << ret << endl;
	
	system("pause");
	return 0;
}