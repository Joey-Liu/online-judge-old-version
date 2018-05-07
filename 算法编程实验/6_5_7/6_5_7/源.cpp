#include <iostream>
#include <string.h>
using namespace std;

const int maxn = 500;
char str1[maxn],str2[maxn];
int c[maxn][maxn];

void LCS()
{
	memset(c,0,sizeof(c));
	int m = strlen(str1 + 1);
	int n = strlen(str2 + 1);

	for(int i = 1;i <= m;i++)
		c[i][0] = 0;
	for(int i = 1;i <= n;i++)
		c[0][i] = 0;

	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(str1[i]==str2[j])
				c[i][j] = c[i -1][j - 1] + 1;
			else if(c[i - 1][j] >= c[i][j -1])
				c[i][j] = c[i -1][j];
			else
				c[i][j] = c[i][j -1];
		}
	}
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>(str1 + 1)>>(str2 + 1))
	{
		LCS();
		cout<<c[strlen(str1 + 1)][strlen(str2 + 1)]<<endl;
	}
	return 0;
}