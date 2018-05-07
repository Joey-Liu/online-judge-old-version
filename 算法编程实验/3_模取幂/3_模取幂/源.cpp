#include <iostream>
using namespace std;

const int maxn = 50;
int k[maxn];//�洢ָ���Ķ�������
int index = 0;

int mod_exp(int a,int b,int n)// ����a^b % n,ʵ����cûʲô����
{
	int c = 0;
	int d = 1;
	int tmp = b;

	while(tmp != 0)
	{
		k[index++] = tmp % 2;
		tmp /= 2;
	}
	index--;

	for(int i = index;i >= 0;i--)
	{
		c *= 2;
		d = (d * d) % n;
		if(k[i]==1)
		{
			c++;
			d =(d * a) % n;
		}
	}
	return d;
}

int main()
{
	freopen("out.txt","w",stdout);
	cout<<mod_exp(7,560,561)<<endl;
	return 0;
}