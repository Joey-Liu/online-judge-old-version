#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;


class Solution {
public:
	string convert(string s, int numRows) 
	{
		if (1 == numRows)
			return s;
		vector<string> rowStr;
		for (int i = 0; i < numRows; i++)
		{
			string str;
			rowStr.push_back(str);
		}

		bool flag = true;
		int indRow = 0;
		for (int i = 0; i < s.length(); i++)
		{

			rowStr[indRow] += s[i];

			int dup = i / (numRows - 1);			
			if (0 == dup % 2)
				flag = true;
			else
				flag = false;

			if (flag)
				indRow++;
			else
				indRow--;


		}
		string resStr = "";
		for (int i = 0; i < rowStr.size(); i++)
			resStr += rowStr[i];
		return resStr;
	}
};

int main()
{
	Solution so;
	so.convert("ABCD", 3);
}