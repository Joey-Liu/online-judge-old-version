#include <iostream>
using namespace std;

const int maxn = 20000 + 500;
long long int p[maxn];

long int len;//¶ÑÎ²Ö¸Õë

void insert(long long int k)
{
	long t = ++len;
	p[t] = k;
	while(t > 1)
	{
		if(p[t/2] > p[t])
		{
			swap(p[t],p[t/2]);
			t /= 2;
		}
		else
			break;
	}
}

void pop()
{
	long t = 1;
	p[t] = p[len--];
	while(t*2 <= len)
	{
		long int k = t*2;
		if(k < len && p[k + 1] < p[k])
			k++;
		if(p[t] > p[k])
		{
			swap(p[t],p[k]);
			t = k;
		}
		else
			break;
	}
}

int main()
{
	long n;
	cin>>n;
	for(long i = 1;i <= n;i++)
		cin>>p[i];
	len = 0;
	for(long i = 1;i <= n;i++)
		insert(p[i]);
	
	long long int result = 0;
	while(len > 1)
	{
		long a,b;

		a = p[1];
		pop();
		b = p[1];
		pop();

		result += (a + b);
		insert(a + b);
	}
	cout<<result<<endl;
	system("pause");
	return 0;
}
