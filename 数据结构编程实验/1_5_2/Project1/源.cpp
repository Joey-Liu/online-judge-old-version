#include <iostream>
struct stack
{
	int *base;
	int top;
	int size;
};
using namespace std;
const int maxn = 15;
int turn(int num,int rule,stack tony)
{
	tony.base = new int[maxn];
	tony.top = tony.size = 0;
	int sum=0;
	while(num)
	{
		tony.base[tony.top]= num%rule;
		tony.top++;
		tony.size++;
		num /=rule;
	}
	while(tony.top > 0)
	{
		sum += tony.base[tony.top-1];
		tony.top--;
		tony.size--;
	}
	return sum;
}

int main()
{
	int i = 2992;
	stack joe =
	{NULL,0,0};

	for(i = 2992; i < 10000; i++)
	{
		int sum1 = turn(i,10,joe);
		int sum2 = turn(i,16,joe);
		int sum3 = turn(i,12,joe);
		if(sum1==sum2 && sum1==sum3)
			cout<<i<<endl;
	}
	system("pause");
	return 0;
}
