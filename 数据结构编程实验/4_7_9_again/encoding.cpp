#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=1500;
int main()
{
//	freopen("encoding.in.txt","r",stdin);
//	freopen("output2.0.txt","w",stdout);
	char s[maxn],tmp;							//tmp[max]->tmp,no j
	int i,len,cnt=1;
	while(gets(s))
	{
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(s[i]==s[i+1] && i+1 < len)				//有相同字符 && i+1 != '\0' 
			{
				tmp=s[i];
				cnt=2;
				i++;
			
				while(cnt < 9 && i+1 < len)					//重复的字符小于九个 && 未到最后一个字符
				{
					if(tmp!=s[i+1])
						break;
					cnt++;
					i++;
				}
				cout<<cnt<<tmp;
				cnt=1;					
										//此时for循环还会使i++
			}
			else 						//字符不相同 || 目前字符为最后一个
			{	
				cout<<'1';				//先给出1
				while(i < len)            //输出各不相同的字符
				{
					if(i+1 < len && s[i+1]==s[i])
						break;
					cout<<s[i];
					if('1'==s[i])
						cout<<'1';			//如果是1，则输出11
					 i++;
				}
				cout<<'1';
				i--;								//for循环会使i++,从而到下一个字
			}
		}//for
		cout<<endl;
	}//while
	return 0;
}