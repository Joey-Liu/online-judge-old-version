#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;
int N, peo[2];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string str;
	cin >> N >> peo[0] >> peo[1];
	cin >> str;
	
	int state = 0, res = 0, sit = -1;
	for (int i = 0; i < N; i++) {
		if ('*' == str[i]) {
			state = 0;
			continue;
		}

		if ('.' == str[i] && 0 == state) {
			state = 1;
			sit = (peo[0] >= peo[1] ? 0 : 1);
			if (peo[sit] > 0) {
				peo[sit]--;
				res++;
			}
		}
		else if ('.' == str[i] && 1 == state) {
			sit = 1 - sit;
			if (peo[sit] > 0) {
				peo[sit]--;
				res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}