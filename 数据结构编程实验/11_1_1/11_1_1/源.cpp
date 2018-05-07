#include <iostream>
#include <memory.h>
using namespace std;

struct node 
{
	int k,step;
};

node h[1000000];//BFS队列
bool p[11000];//素数表
int s[11000];//素数最断续序列

void makeprime(int n)
{
	memset(p,0,sizeof(p));//0为素数，1为合数
	p[0] = 1;
	p[1] = 1;
	for(int i = 2;i <= n;i++)
	{
		if(!p[i])
		{
			for(int j = i*2;j <= n;j += i)
				p[j] = 1;
		}
	}
}

int change(int x,int i,int j)//把x的第i位数字改为j
{
	if(1==i)
		return (x/10)*10 + j;
	if(2==i)
		return (x/100)*100 + x%10 + j*10;
	if(3==i)
		return (x/1000)*1000 + x%100 +j*100;
	if(4==i)
		return x%1000 + j*1000;
}

int main()
{
	freopen("primepath.in","r",stdin);
	freopen("out.txt","w",stdout);
	makeprime(10000);
	int casenum;
	cin>>casenum;
	
	while(casenum--)
	{
		int ans = -1;
		int lp = 1,rp = 1;//队列左右指针，队列初始化
		memset(s,100,sizeof(s));//素数访问初始化
		int x,y;
		cin>>x>>y;

		h[1].k = x;
		h[1].step = 0;//从x结点开始遍历

		while(true)
		{
			if(h[lp].k==y)
			{
				ans = h[1].step;
				break;
			}
			///开始遍历当前结点的子节点
			int tk,ts;
			for(int i = 1;i <= 4;i++)
			{
				for(int j = 0;j <= 9;j++)
				{
					if(!(0==j && 4==i))
					{
						tk = change(h[lp].k,i,j);
						if(p[tk])
							continue;
						ts = h[lp].step + 1;
						if(ts >= s[tk])//说明之前访问过这个节点
							continue;
						s[tk] = ts;
						if(tk==y)
						{
							ans = ts;
							break;
						}
						h[++rp].k = tk;
						h[rp].step = ts;
					}
				}
			}//int i
			if(ans > 0 || lp==rp)//得到answer 或 没有节点继续入队
				break;
			lp++;//结点出队
		}//while(true)
		if(ans >= 0)
			cout<<ans<<endl;
		else
			cout<<"Impossible"<<endl;
	}//while(casenum)
	return 0;
}