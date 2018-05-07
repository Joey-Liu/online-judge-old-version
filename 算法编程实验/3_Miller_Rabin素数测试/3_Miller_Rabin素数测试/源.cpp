#include <iostream>
using namespace std;

const int maxn = 100;
int k[maxn];//�洢ָ���Ķ�������
int index = 0;

int mod_exp(int a,int b,int n)// ����a^b % n
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

bool witness(int a,int n)//��a����n�Ƿ�Ϊ������nΪ����
{
	int u,t = 0,tmp = n -1;

	//��n-1ת��Ϊ2^t * u��uΪ����
	while(!(tmp % 2))
	{
		tmp /= 2;
		t++;
	}
	u = tmp;

	int res,pre;
	res = mod_exp(a,u,n);// ����a^u % n
	pre = res;

	for(int i =1;i <= t;i++)
	{
		res = pre * pre % n;
		if(res==1 && pre != 1 && pre != n - 1)//���ֺ���
			return true;
		pre = res;//����������ˡ�����
	}
	
	if(res != 1)
		return true;
	return false;
}

bool Miller_Rabin(int n,int s)//s�����ֶ�n���в���
{
	int a;
	for(int i = 1;i <= s;i++)
	{
		a = rand() % (n - 1) + 1;//ע���ֹ0���֣���������
		if(witness(a,n))
			return true;	//�����Ǻ���
	}
	return false;//������������
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