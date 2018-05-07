#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

const int maxn = 60000 + 100;
const int cmaxn = 50;

struct msg
{
	char name[cmaxn];
	int para;//参数
	int pri;//优先级
	int order;//次序
}p[maxn];
int heap[maxn];

int used;//p 指针
int top;//堆尾指针

int cmp(msg p1,msg p2)
{
	if(p1.pri < p2.pri)//1 小(在小根堆中)
		return -1;
	if(p1.pri > p2.pri)
		return 1;
	if(p1.order < p2.order)
		return -1;
	if(p1.order > p2.order)
		return 1;
	printf("error!\n");
	return 0;
}

void mswap(int & a,int & b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void insert()//used 未更新
{
	int k = ++top;//top不超尾
	heap[k] = used++;//used超尾
	while(k > 1)
	{
		int t = k/2;
		if(cmp(p[heap[t]],p[heap[k]]) > 0)//k向上移
		{
			mswap(heap[t],heap[k]);
			k = t;
		}
		else
			break;
	}
}

void remove()
{
	if(top ==0)//堆为空
	{
		printf("EMPTY QUEUE!\n");
		return;
	}
	int k = 1;
	printf("%s %d\n",p[heap[1]].name,p[heap[1]].para);

	//调整堆
	heap[k] = heap[top--];
	while(k*2 <= top)
	{
		int tmp  =k*2;
		if(tmp < top && cmp(p[heap[tmp + 1]],p[heap[tmp]]) < 0)
			tmp++;
		if( cmp(p[heap[tmp]],p[heap[k]]) < 0 )
		{
			mswap(heap[tmp],heap[k]);
			k = tmp;
		}
		else
			break;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	used = 0;
	top = 0;
	int cnt = 0;//消息顺序
	string str;
	while(cin>>str)
	{
		if("PUT"==str)
		{
			cin>>p[used].name>>p[used].para>>p[used].pri;
			p[used].order = cnt++;
			insert();
		}
		else
			remove();
	}
	return 0;
}