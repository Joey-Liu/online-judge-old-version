#include <iostream>
using namespace std;

const int maxn = 100;
int k[maxn];//存储指数的二进制数
int index = 0;

int mod_exp(int a,int b,int n)// 计算a^b % n
{
	index = 0;
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
		d = (d * d) % n;
		if(k[i]==1)
			d =(d * a) % n;
	}
	return d;
}

bool witness(int a,int n)//用a测试n是否为素数，n为奇数
{
	int u,t = 0,tmp = n -1;

	//将n-1转换为2^t * u，u为奇数
	while(!(tmp % 2))
	{
		tmp /= 2;
		t++;
	}
	u = tmp;

	int res,pre;
	res = mod_exp(a,u,n);// 计算a^u % n
	pre = res;

	for(int i =1;i <= t;i++)
	{
		res = pre * pre % n;
		if(res==1 && pre != 1 && pre != n - 1)//出现合数
			return true;
		pre = res;//把这个都忘了。。。
	}
	
	if(res != 1)
		return true;
	return false;
}

bool Miller_Rabin(int n,int s)//s个数字对n进行测试
{
	int a;
	for(int i = 1;i <= s;i++)
	{
		a = rand() % (n - 1) + 1;//注意防止0出现！！！！！
		if(witness(a,n))
			return true;	//绝对是合数
	}
	return false;//基本上是素数
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	srand(time_t(NULL));
	int number;
	while(cin>>number)
	{
		if(Miller_Rabin(number,(number - 1) / 2 ))
			cout<<"COMPOSITE"<<endl;
		else
			cout<<"PRIME"<<endl;
	}
	return 0;
}