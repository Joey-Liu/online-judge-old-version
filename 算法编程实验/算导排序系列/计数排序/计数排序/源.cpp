//��������(��Ԫ�ؾ�Ϊ�Ǹ�����)
#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 50;
int Size = 8;

int a[maxn] = {2,5,3,0,2,3,0,3};
int b[maxn];//�洢�������˳��
int c[maxn];//c[lp...rp],lp,rpӦ�ֱ��Ӧ���� ��С�����ֵ����lp <= min(a),rp >= max(a)
			//c[i]���� <= iԪ�ظ�������i��������λ��
void counting_sort()
{
	memset(c,0,sizeof(c));
	memset(b,-1,sizeof(b));

	for(int i = 0;i < Size;i++)
		c[a[i]]++;
	for(int i = 1;i < Size;i++)
		c[i] += c[i - 1];

	for(int i = 0;i < Size;i++)
	{
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
}

int main()
{
	freopen("out.txt","w",stdout);
	counting_sort();
	for(int i = 0;i < maxn;i++)
		if(-1 != b[i])
			cout<<b[i]<<" ";
	return 0;
}