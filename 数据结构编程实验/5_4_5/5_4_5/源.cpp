#include <iostream>
#include <string>
#include <string.h>
const int maxn = 100 + 13;
using namespace std;

string s,t;							//初始串，目标串
char ans[maxn],stack[maxn];			//出栈序列，栈
int len = 0,top =0;				//ans stack 指针

void solve(int ks,int kt)
{
	if(kt==t.size() && top==0)				//先放前面试试，加个top==0,个人认为是kt==s.size
	{                                       //经测试，应该按上面的判断条件（top==0）
		for(int j = 0;j < len;j++)
			cout<<ans[j]<<' ';
		cout<<endl;
		return;
	}
	if(ks < s.size())
	{
		ans[len++] = 'i';
		stack[top++] = s[ks];			//先入栈
		solve(ks + 1,kt);				
		len--;
		top--;							//再出栈
	}
	if(top != 0 && stack[top-1]==t[kt])
	{
		ans[len++] = 'o';
		char temp = stack[top - 1];
		top--;
		solve(ks,kt + 1);				//等于说是匹配了一个
		len--;							//恢复之前状态
		stack[top++] = temp;
	}
}




int main()
{
	while (cin>>s>>t)
	{
		cout<<'['<<endl;
		if(s.size() != t.size())
			cout<<']'<<endl;
		else
		{
			solve(0,0);
			cout<<']'<<endl;
		}
	}
	return 0;
}
