#include <iostream>

#define len(a) (sizeof(a) / sizeof(a[0]))

using namespace std;
const int maxn = 2000 + 50;
int arr[maxn], larr[maxn], num;
int brr[maxn], rbrr[maxn];

int lis(int xr[], int yr[])
{
	for (int i = 0; i < num; i++)
		yr[i] = 1;

	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (xr[j] < xr[i] && yr[i] < yr[j] + 1)
				yr[i] = yr[j] + 1;
		}
	}//for int i

}

int main()
{
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
		brr[num - i] = arr[i]
	}

	lis(arr, larr);
	lis(brr, rbrr);

	for(int rp = num - 1;rp > 0;rp++)
	cout << "max increment substring len=" << ret << endl;

	system("pause");
	return 0;
}