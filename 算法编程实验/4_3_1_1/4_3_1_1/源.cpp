#include <iostream>
#include <stdlib.h>
using namespace std;

const int maxn = 10000 + 5;

int num;
int sum[maxn], mode[maxn], node[maxn];//sum[i] 为前i个数之和，mod[k]为前n个数之和模

void print(int st, int en,int ar[])
{
	cout << en - st + 1 << endl;
	while (st <= en)
	{
		cout << ar[st] << endl;
		st++;
	}
}

int main()
{
	freopen("3", "r", stdin);
	freopen("out.txt", "w", stdout);

	memset(node, 0, sizeof(node));
	memset(sum, 0, sizeof(sum));
	memset(mode, 0, sizeof(mode));

	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> node[i];
		sum[i] = sum[i - 1] + node[i];
	}

	for (int i = 1; i <= num; i++)
	{
		if (0 == sum[i] % num)
		{
			print(1, i, node);
			break;
		}
		else if (!mode[sum[i] % num])
		{
			mode[sum[i] % num] = i;
		}
		else
		{
			print(mode[sum[i] % num] + 1, i, node);
			break;
		}
	}
	return 0;
}