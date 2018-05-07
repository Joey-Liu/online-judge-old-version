#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

int N;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	if (N <= 5)
		cout << -1 << endl;
	else
	{
		int K = N - 1;
		int ln = 0;
		if (0 == K % 2)
			ln = K / 2;
		else
			ln = K / 2 + 1;

		for (int i = 2; i <= 1 + ln; i++)
			cout << 1 << " "<<i << endl;
		for (int i = 2 + ln; i <= N; i++)
			cout << ln + 1 << " " << i << endl;
	}
	for (int i = 2; i <= N; i++)
		cout << 1 << " " << i << endl;
	return 0;
}