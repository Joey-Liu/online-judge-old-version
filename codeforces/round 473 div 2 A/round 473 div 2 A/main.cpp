#include <iostream>
#include <stdio.h>

using namespace std;

int N;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	bool Mah = false;
	cin >> N;

	if (0 == N % 2)
		Mah = true;
	else
		Mah = false;
	if (Mah)
		cout << "Mahmoud" << endl;
	else
		cout << "Ehab" << endl;
	return 0;
}