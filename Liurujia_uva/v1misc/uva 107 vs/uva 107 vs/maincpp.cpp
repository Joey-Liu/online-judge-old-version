#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>

using namespace std;
double N, M, K, H, S, SH;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> H >> M)
	{
		if (!H && !M)
			break;

		N = 1;
		double a = log(M);
		double b = log(H);
		double c = log(N);
		double d = log(N + 1);
		while (abs(a / b - c / d) > 1e-6)
		{
			N++;
			a = log(M);
			 b = log(H);
			c = log(N);
			 d = log(N + 1);
		}
		K = (int)(log(H) / log(N + 1) + 0.5);
		if (1 == N)
			S = K;
		else
			S = int((pow(N, K) - 1) / (N - 1) + 0.5);
		cout << S << ' ';
		SH = int((1 - pow(N / (1 + N), K + 1)) * H * (N + 1) + 0.5);
		cout << SH << endl;
	}//while cin
	return 0;
}
