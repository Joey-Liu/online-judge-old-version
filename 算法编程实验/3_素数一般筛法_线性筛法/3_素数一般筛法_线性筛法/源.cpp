/*
//http://blog.csdn.net/dinosoft/article/details/5829550
//线性筛法依据上述博文 含证明

#include <iostream>
using namespace std;

const int maxn = 20000 * 5;
bool prime[maxn];
int ans[maxn];
int cnt = 0;

void make_prime()
{
	memset(prime,true,sizeof(prime));
	prime[0] = prime[1] = false;

	for(int i = 2;i < maxn;i++)
	{
		if(prime[i])
		{
			ans[++cnt] = i;
			for(int k = i * i;k < maxn;k += i)
				prime[k] = false;
		}
	}
	return;
}

int main()
{
	freopen("out.txt","w",stdout);
	make_prime();
	for(int i = 1;i <= cnt;i++)
	{
		cout<<ans[i]<<" ";
		if(0==i%50)
			cout<<endl;
	}
	int a = 13;
	return 0;
}
*/

#include <iostream>
using namespace std;

const long maxn = 2000000;
long prime[maxn] = {0};//基于0
long num_prime = 0;
int isNotPrime[maxn] = {1,1};//除了0,1外其余都是素数

int main()
{
	freopen("out.txt","w",stdout);
	for(long i = 2;i < maxn;i++)//依次枚举各个数字
	{
		if(!isNotPrime[i])
			prime[num_prime++] = i;
		
		//进行线性筛除
		for(long j = 0;j < num_prime && i * prime[j] < maxn;j++)
		{
			isNotPrime[i * prime[j]] = 1;//把小于 i 的素数 和 i 的乘积置为合数这里可以分为两种情况 1.i是素数  2.i不是素数
			if(!(i % prime[j]))//只筛除不大于 其最小质因数 与 i 的乘积
				break;
		}
	}
	for(int i = 0;i < num_prime;i++)
	{
		if(0==i % 50)
			cout<<endl;
		cout<<prime[i]<<" ";
	}
	return 0;
}

