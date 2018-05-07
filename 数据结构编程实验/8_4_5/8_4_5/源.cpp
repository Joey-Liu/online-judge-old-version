#include <iostream>
#include <memory.h>
using namespace std;
const int maxn = 5000;

int set[maxn];

int set_find(int p)
{
	if(set[p] < 0)
		return p;
	else
		return set[p] = set_find(set[p]);
}

void join(int p,int q)//°Ñp²¢Èëq
{
	p = set_find(p);
	q = set_find(q);
	if(p != q)
		set[p] = q;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum,num,n1,n2,a,b;
	char ch;
	bool flag = true;

	while(1==scanf("%d",&num) && num != 0)
	{
		memset(set,-1,sizeof(set));
		n1 = n2 = 0;
		getchar();

		while(1==scanf("%c",&ch))
		{
			if(ch != 'c' && ch != 'q')
			{
				ungetc(ch,stdin);
				break;
			}
			scanf("%d%d",&a,&b);
			getchar();

			if('c'==ch)
				join(a,b);
			else
			{
				if(set_find(a) != set_find(b))
					n2++;
				else
					n1++;
			}
		}
		printf("%d, %d\n",n1,n2);
	}
	return 0;
}