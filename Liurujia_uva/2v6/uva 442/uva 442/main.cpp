#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <stack>

using namespace std;

struct Matrix
{
	int row, col;
	Matrix(int r = 0, int c = 0)
	{
		row = r;
		col = c;
	}
};

map<char, Matrix> mats;
int N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char c;
		int ro, co;
		cin >> c >> ro >> co;
		Matrix ma(ro, co);
		mats[c] = ma;
	}
	
	string expression;
	while (cin >> expression)
	{
		stack<Matrix> s;
		bool flag = true;
		int res = 0;

		for (int i = 0; i < expression.size(); i++)
		{
			if (expression[i] == '(')
				continue;
			else if (expression[i] == ')')
			{
				Matrix b = s.top(); s.pop();
				Matrix a = s.top(); s.pop();
				if (a.col != b.row)
				{
					flag = false;
					break;
				}
				res += a.row * a.col * b.col;
				Matrix re(a.row, b.col);
				s.push(re);
			}
			else
				s.push(mats[expression[i]]);
		}
		if (!flag)
			cout << "error" << endl;
		else
			cout << res << endl;
	}//while
	return 0;
}