//���ַ���ƽ�����ǲ��ܽ������ģ�ѧ�����ݰɡ�����
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef long long LL;

inline LL mod_pro(LL a,LL b,LL n)// a * b % n
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

inline LL mod_exp(LL a,LL b,LL n)//a^b % n
{
	LL r = 1,d = a;
	while(b)//b �����Ʊ�ʾ
	{
		if(b & 1)
			r = mod_pro(r,d,n);
		d = mod_pro(d,d,n);
		b >>= 1;
	}
	return r;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	LL n,m,tn,res;
	n = 50;
	m = 100000*2;
	//while(scanf("%lld %lld",&n,&m) != EOF)
	for(int i = 1;i < 50;i++)
	{
		if(1==m)
		{
			printf("0\n");
			continue;
		}
		//tn = n / 2;
		tn = i / 2;

		if(0 != tn)
		{
			res = mod_exp(4,tn,m);//����ط�ȡģʱ���ܳ�������
			res--;
			if(res < 0)
				res += m;
		}
		else
			res = 0;

		res = res / 3 * 2;
		if(!(i % 2))
			printf("%lld\n",res);
		else
		{
			res = mod_pro(res,2,m);
			res++;
			res = mod_pro(res,1,m);
			printf("%lld\n",res);
		}
	}
	return 0;
}
