#include <stdio.h>
#include <memory.h>
const int maxn = 100000 + 100;

int set[maxn];//记录每个元素的栈低（代表元素）元素
int top[maxn];//记录每个元素的栈顶元素
int cnt[maxn];//j记录每个元素到栈低的元素个数

int set_find(int p)//查找元素p的栈底元素，并进行路径压缩，并更新 p 到栈底元素的个数
{
	if(set[p] < 0)//本身为栈底元素
		return p;
	
	if(set[set[p] ] >= 0)//p的栈底元素set[p]并不是真正的栈底元素（也就是说p的栈底元素下面还有其他元素）
	{
		int tmp = set[p];
		set[p] = set_find(tmp);//压缩路径
		cnt[p] += cnt[tmp];		//累加 p 到栈底元素的数量，注意tmp到新的栈底元素的数量 在 set_join 函数中已经更新	
	}
	return set[p];//返回栈底元素
}

void set_join(int x,int y)
{
	x = set_find(x);
	y = set_find(y);//x y 变为各自的栈底元素

	set[x] = y;		//x 栈底元素换为 y 
	set_find(top[y]);//保证top[y]到栈底元素的个数(cnt[top[y] ])正确
	cnt[x] = cnt[top[y] ] + 1; // 更新x 到新栈底元素的个数
	top[y] = top[x]; //y 的栈顶元素换为x 栈顶元素，只用改变 栈底 所记录的 栈顶元素即可 （其他的也用不到）
}

int main()
{
	freopen("cubes.10.in","r",stdin);
	freopen("out10.txt","w",stdout);
	memset(set,-1,sizeof(set));
	memset(cnt,0,sizeof(cnt));
	for(int i =0 ;i < maxn;i++)
		top[i] = i;

	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		char c;
		int a,b;
		
		getchar();
		scanf("%c",&c);
		if('M'==c)
		{
			scanf("%d%d",&a,&b);
			set_join(a,b);
		}
		else
		{
			scanf("%d",&a);
			set_find(a);//更新a到栈底元素的个数
			printf("%d\n",cnt[a]);
		}
	}
	return 0;
}