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
			if(s[i]==s[i+1] && i+1 < len)				//����ͬ�ַ� && i+1 != '\0' 
			{
				tmp=s[i];
				cnt=2;
				i++;
			
				while(cnt < 9 && i+1 < len)					//�ظ����ַ�С�ھŸ� && δ�����һ���ַ�
				{
					if(tmp!=s[i+1])
						break;
					cnt++;
					i++;
				}
				cout<<cnt<<tmp;
				cnt=1;					
										//��ʱforѭ������ʹi++
			}
			else 						//�ַ�����ͬ || Ŀǰ�ַ�Ϊ���һ��
			{	
				cout<<'1';				//�ȸ���1
				while(i < len)            //���������ͬ���ַ�
				{
					if(i+1 < len && s[i+1]==s[i])
						break;
					cout<<s[i];
					if('1'==s[i])
						cout<<'1';			//�����1�������11
					 i++;
				}
				cout<<'1';
				i--;								//forѭ����ʹi++,�Ӷ�����һ����
			}
		}//for
		cout<<endl;
	}//while
	return 0;
}