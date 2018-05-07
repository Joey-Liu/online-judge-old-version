/*
//http://blog.csdn.net/dinosoft/article/details/5829550
//����ɸ�������������� ��֤��

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
long prime[maxn] = {0};//����0
long num_prime = 0;
int isNotPrime[maxn] = {1,1};//����0,1�����඼������

int main()
{
	freopen("out.txt","w",stdout);
	for(long i = 2;i < maxn;i++)//����ö�ٸ�������
	{
		if(!isNotPrime[i])
			prime[num_prime++] = i;
		
		//��������ɸ��
		for(long j = 0;j < num_prime && i * prime[j] < maxn;j++)
		{
			isNotPrime[i * prime[j]] = 1;//��С�� i ������ �� i �ĳ˻���Ϊ����������Է�Ϊ������� 1.i������  2.i��������
			if(!(i % prime[j]))//ֻɸ�������� ����С������ �� i �ĳ˻�
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

