#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

typedef long long LL;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, res = 0;
	string str;
	cin >> n >> str;
	int ind = 0;

	while (ind < str.size() - 1)
	{
		if (str[ind] != str[ind + 1])
		{
			res++;
			ind += 2;
		}
		else
			ind += 1;
	}//ind
	cout << n - res << endl;
	return 0;
}