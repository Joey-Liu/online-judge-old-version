//这道题在题目上说明了 1 是素数
#include <iostream>
#include <string>

using namespace std;

const int maxn = 1000 + 500;
int prime[maxn];
int num_prime = 0;
int isNotPrime[maxn] = {1,1};

void prepare()
{
	for(int i = 2;i < maxn;i++)
	{
		if(!isNotPrime[i])
			prime[num_prime++] = i;
		for(int j = 0;j < num_prime && i * prime[j] < maxn;j++)
		{
			isNotPrime[prime[j] * i] = 1;
			if(!(i % prime[j]))
				break;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string str;
	int sum;
	prepare();
	isNotPrime[1] = 0;
	while(cin>>str)
	{
		sum = 0;
		for(int i = 0;i < str.size();i++)
		{
			if(str[i] >= 'a' && str[i] <= 'z')
				sum += (1 + str[i] - 'a');
			else
				sum += (str[i] - 'A' + 27);
		}
		if(isNotPrime[sum])
			cout<<"It is not a prime word."<<endl;
		else
			cout<<"It is a prime word."<<endl;
	}
	return 0;
}