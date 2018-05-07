#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100 + 10;
char enc[maxn], ori[maxn];
int cnt1[26], cnt2[26];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (2 == scanf("%s%s", enc, ori))
	{
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));

		for (int i = 0; i < strlen(enc); i++)
			cnt1[enc[i] - 'A']++;
		for (int i = 0; i < strlen(ori); i++)
			cnt2[ori[i] - 'A']++;

		sort(cnt1, cnt1 + 26);
		sort(cnt2, cnt2 + 26);
		bool flag = true;
		for (int i = 0; i < 26; i++)
			if (cnt1[i] != cnt2[i])
			{
				flag = false;
				break;
			}
		const char *res = (flag ? "YES" : "NO");
		cout << res << endl;
	}//while
	return 0;
}