#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

bool work(int &W)
{
	int wl, dl, wr, dr;
	bool left = true, right = true;
	cin >> wl >> dl >> wr >> dr;
	if (!wl)
		left = work(wl);
	if (!wr)
		right = work(wr);

	W = wl + wr;
	return (left && right && (wl * dl == wr * dr));
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	cin >> kasenum;
	while (kasenum--)
	{
		int W;
		if (work(W))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		if (kasenum)
			cout << endl;
	}
	return 0;
}