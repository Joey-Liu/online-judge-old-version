#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
long long int gcd, lcm;

int main()
{
	int kase;
	cin >> kase;
	while (kase--)
	{
		cin >> gcd >> lcm;
		if (lcm % gcd == 0)
			cout << gcd << " " << lcm << endl;
		else
			cout << "-1" << endl;
	}
}