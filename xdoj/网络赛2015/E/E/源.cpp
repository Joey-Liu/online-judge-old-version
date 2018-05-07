//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//using namespace std;
//
//const double a = 1 + sqrt(2);
//const double b = 1 - sqrt(2);
//const double c = 2 * sqrt(2);
//const int m = 1000000007;
//
//typedef long long LL;
//int main()
//{
//	freopen("out.txt", "w", stdout);
//	double ans = 0.0;
//	int n;
//	/*while (cin >> n)
//	{
//		ans = pow(a, n) + pow(b, n);
//		ans /= c;
//		LL res = (LL) (ans + 0.5);
//		res %= 1000000007;
//		cout << res << endl;
//	}*/
//	cout << (int)0 << endl;
//	cout << (int)1 << endl;
//
//	for (n = 2; n < 1000; n++)
//	{
//		ans = pow(a, n) + pow(b, n);
//		ans /= c;
//		ans = (LL)(ans + 0.5);
//		LL res = ans;
//		res %= 1000000007;
//		cout << res << endl;
//	}
//
//	cout << pow(a, 50) << endl;
//	cout << pow(a, 51) << endl;
//	cout << pow(a, 52) << endl;
//	cout << pow(a, 51) + pow(a,52) << endl;
//
//
//
//	return 0;
//}


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <memory.h>

using namespace std;

const int lim = 2;
const int maxn = 1000000007;

typedef long long LL;
struct matrix
{
	LL a[lim][lim];
}origin, res;


matrix multiply(matrix x, matrix y)
{
	matrix temp;
	memset(temp.a, 0, sizeof(temp.a));

	for (int i = 0; i < lim; i++)
	{
		for (int j = 0; j < lim; j++)
		{
			for (int k = 0; k < lim; k++)
			{
				temp.a[i][j] += x.a[i][k] * y.a[k][j];
				temp.a[i][j] %= maxn;
			}
		}
	}//for int i

	return temp;
}

void solve(int n)//
{
	memset(res.a, 0, sizeof(res.a));
	for (int i = 0; i < lim; i++)
		res.a[i][i] = 1;

	origin.a[0][0] = 2;
	origin.a[0][1] = 1;
	origin.a[1][0] = 1;
	origin.a[1][1] = 0;

	while (n)
	{
		if (1 & n)
			res = multiply(res, origin);
		n >>= 1;
		origin = multiply(origin, origin);
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n,ans = 0;
	while (cin >> n)
	{
		if (n == 0 || n == 1)
		{
			cout << n << endl;
			continue;
		}
		n -= 1;
		solve(n);

		cout << res.a[0][0] << endl;
	}
	//for (int n = 0; n < 1000; n++)
	//{
	//	if (0 == n || 1 == n)
	//	{
	//		cout << n << endl;
	//		continue;
	//	}

	//	
	//	solve(n - 1);
	//	cout << res.a[0][0] << endl;
	//}
}