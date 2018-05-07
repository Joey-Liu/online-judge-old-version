#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <math.h>
using namespace std;

int D, T, V1, V2;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> D >> T >> V1 >> V2;
	double dist = D + T * V2;
	double ti = ceil(dist / V1);
	int res = int(ti);
	cout << res << endl;


	return 0;
}