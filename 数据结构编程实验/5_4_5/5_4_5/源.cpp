#include <iostream>
#include <string>
#include <string.h>
const int maxn = 100 + 13;
using namespace std;

string s,t;							//��ʼ����Ŀ�괮
char ans[maxn],stack[maxn];			//��ջ���У�ջ
int len = 0,top =0;				//ans stack ָ��

void solve(int ks,int kt)
{
	if(kt==t.size() && top==0)				//�ȷ�ǰ�����ԣ��Ӹ�top==0,������Ϊ��kt==s.size
	{                                       //�����ԣ�Ӧ�ð�������ж�������top==0��
		for(int j = 0;j < len;j++)
			cout<<ans[j]<<' ';
		cout<<endl;
		return;
	}
	if(ks < s.size())
	{
		ans[len++] = 'i';
		stack[top++] = s[ks];			//����ջ
		solve(ks + 1,kt);				
		len--;
		top--;							//�ٳ�ջ
	}
	if(top != 0 && stack[top-1]==t[kt])
	{
		ans[len++] = 'o';
		char temp = stack[top - 1];
		top--;
		solve(ks,kt + 1);				//����˵��ƥ����һ��
		len--;							//�ָ�֮ǰ״̬
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
