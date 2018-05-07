#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 10;
long int value[maxn];

long input()
{
	char c;
	int flag = 0;
	long sum = 0;
	if((c = getchar()) == '-')
		flag = 1;
	else if(c >= '0' && c <= '9')
		sum = sum + c - '0';
	while((c = getchar()) >= '0' && c <= '9')
		sum = sum * 10 + (c - '0');
	return sum;
}

void output(long a) 
{
    if(a > 9)
		output(a/10);
    putchar(a%10+'0');
}
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)//memset加不加应该都可以
	{
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
			value[i] = input();

		sort(value,value + n);
		int m;
		scanf("%d",&m);
		long desire;
		while(m--)
		{
			desire = input();
			int position =  lower_bound(value,value + n,desire) - value;
			if(position == n)//越界
				printf("-1");
			else
				output(value[position]);
			printf("\n");
		}

	}
	return 0;
}
