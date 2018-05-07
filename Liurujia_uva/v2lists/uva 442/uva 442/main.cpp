#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;
const int maxn = 100 + 50;
struct Matrix
{
	int rows;
	int cols;
};
Matrix mat[26];
int n, rows, cols;
char ch;
char str[maxn];
stack<Matrix> matStack;
long long int res = 0, temp = 0;
bool flag = true;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%c %d %d", &ch, &rows, &cols);
		mat[ch - 'A'].cols = cols;
		mat[ch - 'A'].rows = rows;
		getchar();
	}

	while (EOF != scanf("%s", str))
	{
		res = 0;
		flag = true;
		int length = strlen(str);
		while (!matStack.empty())
			matStack.pop();

		for (int i = 0; i < length; i++)
		{
			if ('(' == str[i])
				continue;

			if (')' != str[i])
				matStack.push(mat[str[i] - 'A']);
			else
			{
				Matrix a = matStack.top();
				matStack.pop();
				Matrix b = matStack.top();
				matStack.pop();

				if (b.cols != a.rows)
				{
					flag = false;
					break;
				}
				res += b.rows * b.cols * a.cols;
				Matrix nm;
				nm.rows = b.rows;
				nm.cols = a.cols;
				matStack.push(nm);
			}
		}
		if (!flag)
			printf("error\n");
		else
			printf("%d\n", res);
	}//while scanf
	return 0;
}