#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int ind = 0;
		while (str[ind] == ' ')
			ind++;

		int sign = 1;
		if (str[ind] == '+' || str[ind] == '-')
			sign = 1 - 2 * (str[ind++] == '-');
		
		long long res = 0;
		while (ind < str.size() && isdigit(str[ind]))
		{
			res = res * 10 + sign * (str[ind] - '0');
			if (res > INT_MAX)
				return INT_MAX;
			if (res < INT_MIN)
				return INT_MIN;
			ind++;
		}
		return (int)res;
	}
};

int main()
{
	Solution so;
	so.myAtoi("-1");
	return 0;
}