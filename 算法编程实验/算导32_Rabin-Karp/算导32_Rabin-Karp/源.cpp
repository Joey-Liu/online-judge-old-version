#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;
const int maxn = 100;//使用整型数组存储字符串对应的数串
int pa[maxn], te[maxn];


bool equals(int a[],int b[],int length)	//数组比较方法
{
	for (int i = 0; i < length; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

//以0-9为字符集
void Rabin_Karp_matcher(string text,string pattern
	,int d,int q)			//t为文本，p为比较模式,d为字符个数，模q
{
	int n = text.length();
	int m = pattern.length();
	int h = (int)(pow(d, m - 1)) % q;
	
	int p = 0, t = 0;		//p为模式pattern的值，t为文本的值
	for (int i = 0; i < n; i++)
		te[i] = text[i] - '0';
	for (int i = 0; i < m; i++)
		pa[i] = pattern[i] - '0';


	for (int i = 0; i < m; i++)
	{
		p = (d * p + pa[i]) % q;
		t = (d * t + te[i]) % q;
	}
	
	cout << "this one has a bug" << endl;
	for (int s = 0; s <= n - m; s++)
	{
		if (t == p)
		{
			if (equals(pa, te + s, m))
				cout << "Pattern occurs with shift " << s << endl;
		}
		if (s != n - m)
		{
			t = (t - te[s] * h) * d + te[s + m];
			t %= q;
			while (t < 0)
				t += q;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string pattern, text;
	cin >> text >> pattern;

	Rabin_Karp_matcher(text, pattern, 10, 13);
	return 0;
}