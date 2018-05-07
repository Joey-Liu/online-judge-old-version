#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
const double PI = acos(-1);
int  casenum, n;
double a, sq;

int main()
{
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%d %lf",&n ,&a);
		sq = n * a * a / tan(PI / n) / 4.0;
		printf("%.4lf\n", sq);
	}
	return 0;
}