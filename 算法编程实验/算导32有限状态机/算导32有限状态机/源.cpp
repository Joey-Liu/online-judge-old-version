#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <math.h>

using namespace std;

const int maxn = 100;		//假设字符集最大有maxn个字符
typedef long long int64;

int delta[maxn][maxn];		//delta为状态转移函数,delta[q][a]为状态q 加上 字符a后的状态,
							//该数组应初始化为0
set<char> sigma;


bool suffix(string p, int k, int q, char a)//p代表整个pattern
{
	char tp[maxn],pk[maxn],pq[maxn];		
	strcpy_s(tp, p.data());

	strncpy_s(pk, tp, k);		//pk中 为原pattern的前k个字符
	strncpy_s(pq, tp, q);
	pq[q] = a;
	pq[q + 1] = '\0';

	for (int i = strlen(pk) - 1,j = strlen(pq) - 1; i >= 0; i--,j--)
	{
		if (pk[i] != pq[j])
			return false;
	}
	return true;
}


void compute_transition_function(string pattern)
{
	int m = pattern.length();
	for (int q = 0; q <= m; q++)	//枚举出所有的状态
	{
		int k;
		for (set<char>::iterator it = sigma.begin(); it != sigma.end(); it++)//在各个状态下，枚举出所有的字符
		{
			k = min(m + 1, q + 2);
			do
			{
				k--;
				if (0 == k)
					break;
			} while (!suffix(pattern,k,q,*it));

			delta[q][*it - 'a'] = k;
		}//for set<char>
	}//int q 
}

void finite_automation_matcher(string pattern, string text)
{
	int n = text.length();
	int q = 0;

	for (int i = 0; i < text.length(); i++)
	{
		q = delta[q][text[i] - 'a'];
		if (q == pattern.length())
		{
			cout << "Pattern occurs with shift " << i - pattern.length() + 1<< endl;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string pattern, text;
	memset(delta, 0, sizeof(delta));
	for (int ch = 97; ch < 123; ch++)
		sigma.insert(ch);

	cin >> pattern >> text;

	compute_transition_function(pattern);
	finite_automation_matcher(pattern, text);
	return 0;
}