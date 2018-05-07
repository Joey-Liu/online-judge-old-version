#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 100;
int diff[maxn];

int input()//处理输入
{
	char c;
	int flag = 0,sum = 0;//flag = 0 时为整数
	if( (c = getchar())=='-')
		flag = 1;
	else if(c >= '0' && c <= '9')
		sum = sum + c - '0';
	while((c = getchar()) >= '0' && c <= '9')
		sum = sum * 10 + (c - '0');
	return sum;
}

void output(int n)
{
	if(n > 9)
		output(n / 10);
	printf("%d",n%10);
}

int main()
{
	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		int kind;
		int desire;
		int fangan = 0;
		scanf("%d",&kind);
		desire = input();

		for(int i = 0;i < kind;i++)
			diff[i] = input();

		sort(diff,diff + kind);

		int ptr;
		for(int i = 0;i < kind;i++)
		{
			for(int j = i + 1;j < kind;j++)
			{
				int need = desire - diff[i] -diff[j];
				ptr = (diff + kind) - lower_bound(diff+j+1,diff+kind,need);
				fangan = fangan + ptr;
			}
		}
		output(fangan);
		printf("\n");
	}
	return 0;
}
