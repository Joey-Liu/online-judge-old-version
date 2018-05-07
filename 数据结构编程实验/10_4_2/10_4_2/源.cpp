#include <iostream>
using namespace std;

const int maxn = 3000 + 100;

struct info
{
	int ID;
	int period;
	int time;
}heap[maxn];

int compare(info a,info b)
{
	if(a.time ==b .time)
		return (a.ID - b.ID);
	return (a.time - b.time);
}

int top = 0;//¶ÑÎ²Ö¸Õë

void mswap(info & a,info  & b)
{
	info tmp = a;
	a = b;
	b =tmp;
}

void insert(info a)
{
	int k = ++top;
	heap[k] = a;
	while(k > 1)
	{
		int t = k / 2;
		if(compare(heap[k],heap[t]) < 0)
		{
			mswap(heap[k],heap[t]);
			k = t;
		}
		else
			break;
	}//k > 1
}

void pop()
{
	if(top)
	{
		printf("%d\n",heap[1].ID);
		int k = 1;
		heap[k] = heap[top--];
		while(k * 2 <= top)
		{
			int t = k *2;
			if(t < top && (compare(heap[t],heap[t + 1]) > 0) )
				t++;
			if(compare(heap[t],heap[k]) < 0)
			{
				mswap(heap[t],heap[k]);
				k = t;
			}
			else
				break;
		}
	}
	else
		return;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char ch[10];
	int id,period;
	info tmp;
	cin>>ch;
	while(0 != strcmp(ch,"#"))
	{
		cin>>id>>period;
		tmp.ID = id;
		tmp.period = period;
		tmp.time = period;
		insert(tmp);
		cin>>ch;
	}

	int req;
	cin>>req;
	for(int i =1;i <= req;i++)
	{
		tmp = heap[1];
		tmp.time += tmp.period;
		pop();
		insert(tmp);
	}

	return 0;
}