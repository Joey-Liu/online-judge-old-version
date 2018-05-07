#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int maxn = 30;
char pre[maxn], mnod[maxn], post[maxn];

//xian zhong hou changdu
void buildPre(char s1[], char s2[], char s3[], int n)
{
	if (n <= 0)
		return;
	char root = s3[n - 1];
	int pos = strchr(s2, root) - s2;
	s1[0] = root;
	buildPre(s1 + 1, s2, s3, pos); //构建左子树
	buildPre(s1 + pos + 1, s2 + pos + 1, s3 + pos, n - pos - 1); // 构建右子树
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%s", post))
	{
		scanf("%s", mnod);
		memset(pre, 0, sizeof(pre));

		int n = strlen(post);
		buildPre(pre, mnod, post, n);
		pre[n] = '\0';
		printf("%s\n", pre);
	}
	return 0;
}