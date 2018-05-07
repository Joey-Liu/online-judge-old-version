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
	r = 0;//���ֻ���ģ
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

LL mod_exp(LL a,LL b,LL n)// ����a^b % n
{/*���������Ӧ��û���⣬��ʱ�����Щ
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


bool witness(LL a,LL n)//��a����n�Ƿ�Ϊ������nΪ����
{
	LL u,t = 0,tmp = n -1;

	//��n-1ת��Ϊ2^t * u��uΪ����
	while(!(tmp % 2))
	{
		tmp /= 2;
		t++;
	}
	u = tmp;

	LL res,pre;
	res = mod_exp(a,u,n);// ����a^u % n
	pre = res;

	for(LL i =1;i <= t;i++)
	{
		//res = pre * pre % n;
		res = mod_pro(pre,pre,n);
		if(res==1 && pre != 1 && pre != n - 1)//���ֺ���
			return true;
		pre = res;//����������ˡ�����
	}

	if(res != 1)
		return true;
	return false;
}

bool Miller_Rabin(LL n,LL s)//s�����ֶ�n���в���,������Ϊtrue������Ϊfalse
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
		a = rand() % (n - 1) + 1;//ע���ֹ0���֣���������
		if(witness(a,n))
			return true;	//���Բ�������
	}
	return false;//������������
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

LL mfind(LL n)//����n����С����
{
	if(!(n & 1))
		return 2;
	if(!Miller_Rabin(n,4))//��n�����Ĵμ��
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