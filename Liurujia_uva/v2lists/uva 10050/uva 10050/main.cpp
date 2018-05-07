#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;
const int maxn = 4000 + 10;
bool days[maxn];
int hparm[maxn], simdays;
int ans = 0;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum, p;
	cin >> kasenum;
	while (kasenum--)
	{
		ans = 0;
		cin >> simdays >> p;
		memset(days, false, sizeof(days));
		for (int i = 0; i < p; i++)
			cin >> hparm[i];

		int index = 0;
		for (int i = 0; i < p; i++)
		{
			index = 0;
			for (; index <= simdays; index += hparm[i])
			{
				if (!days[index] && 0 != index % 7 && 6 != index % 7)
				{
					ans++;
					days[index] = true;
				}
			}
		}
		cout << ans << endl;
	}//while
	return 0;
}