#include <iostream>
#include <string.h>
using namespace std;
const long int maxn=1000;

int main()
{
	int loop;
	cin>>loop;
	while(loop--)
	{
		char w[maxn];
		cin.get();
		cin.get(w,maxn-1);
		int suffix[maxn];
		suffix[0]=-1;
		suffix[1]=0;
		int cur,p=0;
		for(cur=2;cur <= strlen(w); cur++)
		{
			while(p >= 0 && w[p]!=w[cur-1])
				p=suffix[p];
			suffix[cur]=++p;
		}
		for(cur=0;cur <= strlen(w); cur++)
			cout<<suffix[cur] + 1<<"  ";
	}
	return 0;
}
