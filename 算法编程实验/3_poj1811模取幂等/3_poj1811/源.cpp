#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef long long LL;
const int maxn = 150;
LL index = 0;

LL gcd(LL a,LL b)//a > b
{
	while(b != 0)
	{
		LL c = a;
		a = b;
		b = c % b;
	}
	return a;
}

LL mod_pro(LL a,LL b,LL n)// a * b % n
{
	LL r,d;
	r = 0;//部分积的模
	d = a;
	while(b > 0)
	{
		if(b & 1)
			r = (r + d) % n;
		d = (d * 2) % n;
		b >>= 1;
	}
	return r;
}

LL mod_exp(LL a,LL b,LL n)// 计算a^b % n
{/*这样做结果应该没问题，但时间会慢些
	index = 0;
	LL d = 1;
	LL tmp = b;

	while(tmp != 0)
	{
		k[index++] = tmp % 2;
		tmp /= 2;
	}
	index--;

	for(LL i = index;i >= 0;i--)
	{
		d = (d * d) % n;
		if(k[i]==1)
			d =(d * a) % n;
	}
	return d;
*/
	LL r = 1,d = a;
	while(b)
	{
		if(b & 1)
			r = mod_pro(r,d,n);
		d = mod_pro(d,d,n);
		b >>= 1;
	}
	return r;
}


bool witness(LL a,LL n)//用a测试n是否为素数，n为奇数
{
	LL u,t = 0,tmp = n -1;

	//将n-1转换为2^t * u，u为奇数
	while(!(tmp % 2))
	{
		tmp /= 2;
		t++;
	}
	u = tmp;

	LL res,pre;
	res = mod_exp(a,u,n);// 计算a^u % n
	pre = res;

	for(LL i =1;i <= t;i++)
	{
		//res = pre * pre % n;
		res = mod_pro(pre,pre,n);
		if(res==1 && pre != 1 && pre != n - 1)//出现合数
			return true;
		pre = res;//把这个都忘了。。。
	}

	if(res != 1)
		return true;
	return false;
}

bool Miller_Rabin(LL n,LL s)//s个数字对n进行测试,非素数为true，素数为false
{
	if(n < 2)
		return true;
	if(n==2)
		return false;
	if(!(n & 1))
		return true;
	LL a;
	for(LL i = 1;i <= s;i++)
	{
		a = rand() % (n - 1) + 1;//注意防止0出现！！！！！
		if(witness(a,n))
			return true;	//绝对不是素数
	}
	return false;//基本上是素数
}

LL pollard_rho(LL c,LL n)
{
	if(!(n & 1))
		return 2;
	LL i = 1;
	LL x,y,k,d;

	x = rand() % n;
	y = x;
	k = 2;
	do{
		i++;
		d = gcd(n + y -x,n);
		if(d > 1 && d < n)
			return d;
		if(i==k)
		{
			y = x;
			k *= 2;
		}
		x = (mod_pro(x,x,n) + n - c) % n;
	}while(y != x);
	return n;
}

LL mfind(LL n)//查找n的最小因子
{
	if(!(n & 1))
		return 2;
	if(!Miller_Rabin(n,4))//对n进行四次检测
		return n;
	while(true)
	{
		LL t = pollard_rho(rand() % (n - 1) + 1,n);
		if(t < n)
		{
			LL a,b;
			a = mfind(t);
			b = mfind(n / t);
			return a < b ? a : b;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	srand(time(NULL));
	int casenum;
	LL n,ans;
	scanf("%d",&casenum);
	while(casenum--)
	{
		scanf("%lld",&n);
		ans = mfind(n);
		if(ans==n)
		{
			printf("Prime\n");		
		}
		else
		{
			printf("%lld\n",ans);		
		}	
	}
	return 0;
}