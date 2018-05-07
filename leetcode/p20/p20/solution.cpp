#include <string>
#include <stack>

using namespace std;

class Solution 
{
public:
	bool isValid(string s) 
	{
		int ind = 0;
		bool flag = true;
		stack<char> sc;

		while (ind < s.size())
		{
			if (s[ind] == '(' || s[ind] == '{' || s[ind] == '[')
				sc.push(s[ind]);
			else
			{
				if (!sc.empty() && sc.top() == '(' && s[ind] == ')')
					sc.pop();
				else if (!sc.empty() && sc.top() == '{' && s[ind] == '}')
					sc.pop();
				else if (!sc.empty() && sc.top() == '[' && s[ind] == ']')
					sc.pop();
				else
				{
					flag = false;
					break;
				}
			}
			ind++;
		}//while ind
		if (!sc.empty())
			flag = false;
		return flag;
	}
};