#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

char find_sim(string str)
{
	int jin = 16;

	int val = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))
			val = val * jin + (10 + str[i] - 'a');
		else
			val = val * jin + str[i] - '0';
	}

	int ans;
	int mini = 0x3f3f3f;
	for (int j = -1; j <= 1; j++)
	{
		int n = 0;
		if (isalpha(str[0]))
			n = str[0] - 'a' + 10;
		else
			n = str[0] - '0';

		n += j;
		if (n < 0 || n > 15)
			continue;
		
		int v = 0;
		for (int i = 0; i < 2; i++)
		{
			v = v * jin + n;
		}
		int cha = abs(v - val);
		if (cha < mini)
		{
			mini = cha;
			ans = n;
		}
	}

	if (ans < 10)
		return ans + '0';
	return 'a' + ans - 10;
}

class Solution {
public:
	string similarRGB(string color) 
	{
		string res = "#";
		for (int i = 1; i < color.size(); i += 2)
		{
			string s = "aa";
			s[0] = color[i];
			s[1] = color[i + 1];
			char ans = find_sim(s);
			res += ans;
			res += ans;
		}
		return res;
	}

};

int main()
{
	Solution s;
	cout << s.similarRGB("#a0c63f");
	system("pause");
}