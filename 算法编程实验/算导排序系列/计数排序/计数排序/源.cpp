//计数排序(设元素均为非负整数)
#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 50;
int Size = 8;

int a[maxn] = {2,5,3,0,2,3,0,3};
int b[maxn];//存储最后排列顺序
int c[maxn];//c[lp...rp],lp,rp应分别对应数组 最小和最大值，即lp <= min(a),rp >= max(a)
			//c[i]代表 <= i元素个数，即i在排序后的位置
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