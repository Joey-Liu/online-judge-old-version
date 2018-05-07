#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn_char = 50 + 30;
const int maxn_size = 1000;
struct node
{
	char a[maxn_char];
	int x;
}s[maxn_size];

int cmp_x(const void* a,const void* b)
{
	node* m = (node*)a;
	node* n = (node*)b;

	return ((m->x) - (n->x) );					//按逆序数输出
}

void Bubble(node & n,int size)				//size 位字符串长度
{
	int i,j,count =0;
	for(i =0;i < size ;i++)
	{
		for(j=i+1;j < size;j++)
		{
			if(n.a[i] > n.a[j])
			{
				count++;
			}
		}
	}
	n.x = count;
}

int main()
{
	//freopen("G.6.dat","r",stdin);
	//freopen("out6.txt","w",stdout);
	int case_num;
	cin>>case_num;
	
	while(case_num--)
{
	int num,size;
	cin>>num>>size;
	for(int i =0;i < size;i++)
		scanf("%s",s[i].a);

	for(int i=0;i < size;i++)
		Bubble(s[i],num);

	qsort(s,size,sizeof(s[0]),cmp_x);

	for(int i=0;i < size;i++)
		printf("%s\n",s[i].a);
}	
	return 0;
}