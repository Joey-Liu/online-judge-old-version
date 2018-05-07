#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 5000 + 100;
struct node
{
	int length;
	int weight;
	bool used;
}wood[maxn];

int cmp(const void* a,const void* b)
{
	node* _a = (node *)a;
	node* _b = (node *)b;

	if(_a->length != _b->length)
		return (_a->length - _b->length);
	else
		return (_a->weight - _b->weight);
}

int main()
{
	freopen("stick.in","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		int num;
		cin>>num;
		for(int i = 0;i < num;i++)
		{
			cin>>wood[i].length>>wood[i].weight;
			wood[i].used = false;
		}
		qsort(wood,num,sizeof(wood[0]),cmp);

		int mins = 0;
		node tmp = wood[0];
		wood[0].used = true;
		mins = 1;

		while(true)
		{
			for(int i = 0;i < num;i++)
			{
				if(false==wood[i].used && tmp.length <= wood[i].length && tmp.weight <= wood[i].weight)
				{
					wood[i].used = true;
					tmp = wood[i];
				}
			}
			int i = 0;
			for(i = 0;i < num;i++)
			{
				if(!wood[i].used)
				{
					tmp = wood[i];
					wood[i].used = true;
					mins++;
					break;
				}
			}
			if(i==num)
				break;
		}//while(true)
		cout<<mins<<endl;
	}//whilecasenum
	return 0;
}