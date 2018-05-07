/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;
double a, b, c, d, L, R, res[13] = { 0.0 };

double func(double x)
{
	return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

bool in_range(double x)
{
	if (x >= L && x <= R)
		return true;
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> a >> b >> c >> d >> L >> R)
	{
		if (a != 0 && b != 0)
		{

			int flag = true;
			double delta = b* b - 3 * a * c;
			if (delta < 0)
				flag = false;

			if (flag)
			{
				double x1 = (-b + sqrt(delta)) / (3 * a);
				double x2 = (-b - sqrt(delta)) / (3 * a);
				if (in_range(x1) && in_range(x2))
				{
					res[0] = func(x1);
					res[1] = func(x2);
					res[2] = func(L);
					res[3] = func(R);
					for (int i = 0; i < 4; i++)
						res[i] = abs((double)res[i]);
					double ans = -1;
					for (int i = 0; i < 4; i++)
					{
						if (ans < res[i])
							ans = res[i];
					}
					printf("%.2f\n", ans);
				}
				else if (in_range(x1))
				{
					res[0] = func(x1);
					res[1] = func(L);
					res[2] = func(R);
					for (int i = 0; i < 3; i++)
						res[i] = abs((double)res[i]);
					double ans = -1;
					for (int i = 0; i < 3; i++)
					{
						if (ans < res[i])
							ans = res[i];
					}
					printf("%.2f\n", ans);
				}
				else
				{
					res[0] = func(x2);
					res[1] = func(x2);
					res[2] = func(L);
					res[3] = func(R);
					for (int i = 0; i < 4; i++)
						res[i] = abs((double)res[i]);
					double ans = -1;
					for (int i = 0; i < 4; i++)
					{
						if (ans < res[i])
							ans = res[i];
					}
					printf("%.2f\n", ans);
				}
			}
			else
			{
				res[0] = func(L);
				res[1] = func(R);
				for (int i = 0; i < 2; i++)
					res[i] = abs((double)res[i]);

				double ans = -1;
				for (int i = 0; i < 2; i++)
				{
					if (ans < res[i])
						ans = res[i];
				}
				printf("%.2f\n", ans);
			}
		}//if a != 0 && b != 0
		else
		{
			res[0] = func(L);
			res[1] = func(R);
			res[0] = abs(res[0]);
			res[1] = abs(res[1]);

			double ans = res[0] > res[1] ? res[0] : res[1];
			if (a == 0)
			{
				double x = (-c) / (2 * b);
				double y = func(x);
				y = abs(y);
				ans = ans > y ? ans : y;
				printf("%.2f\n", ans);
			}
			else
				printf("%.2f\n", ans);
		}
	}//while
	return 0;
}
*/

