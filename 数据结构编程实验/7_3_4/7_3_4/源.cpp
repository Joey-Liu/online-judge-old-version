#include <iostream>
#include <string>
/*
void Bsort(int a[],int size)
{
	int temp,i, j =0;
	for(i = 0;i < size;i++)
		for(j = 0;j < size - i -1;j++)
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j +1];
				a[j+1] = temp;
			}
}
*/
int Partition(int a[],int low,int high)
{
	int i = low;
	int j = high;
	int pivotkey = a[low];
	while(i < j)
	{
		while(i < j && a[j] >= pivotkey)
			j--;
		a[i] = a[j];
		
		while(i < j && a[i] <= pivotkey)
			i++;
		a[j] = a[i];

	}
	a[i] = pivotkey;
	return i;
}

void Qsort(int num[],int low,int high)
{
	if(low < high)
	{
		int pivoloc = Partition(num,low,high);
		Qsort(num,low,pivoloc -1);
		Qsort(num,pivoloc +1,high);
	}
}




const int maxn = 100000 + 100;
using namespace std;

int main()
{
	freopen("05","r",stdin);
	freopen("output_5.txt","w",stdout);
	int size,num[maxn];
	cin>>size;
	for(int i =0;i < size;i++)
		scanf("%d",&num[i]);
	string s;
	cin>>s;

	Qsort(num,0,size - 1);

	cin>>size;
	while(1==scanf("%d",&size))
		printf("%d\n",num[size-1]);

	system("pause");
	return 0;
}
