#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

class Solution {
public:
	bool isPalindrome(int x) 
	{
		if (x < 0)
			return false;
		
		long long res = 0;
		int tmpx = x;
		while (x != 0)
		{
			int tail = x % 10;
			res = res * 10 + tail;
			x /= 10;

			if (res > INT_MAX || res < INT_MIN)
				return false;
		}
		return ((int)res == tmpx);
	}
};