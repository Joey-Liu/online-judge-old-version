#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h>
#include <sstream>

using namespace std;

int N, K;
string str;

bool valid(string s) {
	int i = s.size() - 1, j = str.size() - 1;
	while (i >=0 && j>=0) {
		if (str[j] == s[i]) {
			j--;
			i--;
		}
		else
			j--;
	}
	if (i < 0)
		return true;
	return false;
}

int work() {
	while (K > 0) {
		int t = K * K;
		string s = to_string(t);
		if (valid(s))
			return str.size() - s.size();
		K--;
	}
	return -1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> str;
	stringstream ss(str);
	ss >> N;

	K = sqrt(N);
	if (K * K == N) {
		cout << 0 << endl;
		return 0;
	}
	int res = work();
	cout << res << endl;
	return 0;
}