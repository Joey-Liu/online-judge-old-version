#include <iostream>
#include <string>
using namespace std;
const int maxl=1120;
int main()
{
	freopen("encoding.in.txt","r",stdin);
	freopen("output.txt","w",stdout);
    char s[maxl];
	char str[maxl];
    while(gets(s))
	{
		int cur=1;
	    int cnt=1;		////////////////////////////////////////////////////
		int len=0;
		memset(str,0,maxl*sizeof(char));
		if('1'==s[0])
			strcpy(str,"11");
		else
			str[0]=s[0];

		for(cur=1;cur<=strlen(s);cur++)					//cur<=strlen(s)
		{
			if((s[cur]==s[cur-1]) && cnt<9)			//cnt<9************
			{
				if(s[cur-1]!=s[cur-2] && strlen(str) >1 && cur > 2)				//替换strlen（str） > 1
				{
					if('1'==s[cur])
						str[strlen(str)-2]='\0';				//
				    else
					    str[strlen(str)-1]='\0';
					cout<<"1"<<str<<"1";
					memset(str,0,maxl*sizeof(char));
				
					str[0]=s[cur];							//有重复的字符（可以包括1）
					cnt=2;
				}    
				else
					cnt++;
			}

			if(s[cur]!=s[cur-1] || cnt >= 9)
			{
				if(1==cnt)
				{
					if('1'==s[cur])
						strcat(str,"11");
					else
					{
						str[strlen(str)]=s[cur];
						str[strlen(str)+1]='\0';
					}
				}
				else if(cnt > 1 && cnt < 9)
				{
					cout<<cnt<<str[0];
					memset(str,0,sizeof(char)*maxl);
					
					str[0]=s[cur];				//*************************
					cnt=1;
					str[0]=s[cur];
				}
				else if(cnt >=9)			///////////////////////////////////////////////////
				{	
					cout<<cnt<<str[0];
					cnt=1;
					memset(str,0,sizeof(char)*maxl);
					cur=0;						//循环最后有一个++

					char tmp[maxl];
					memset(tmp,0,sizeof(char)*maxl);

					strcpy(tmp,s+9);
					strcpy(s,tmp);
					if('1'==s[0])
						strcpy(str,"11");
					else
						str[0]=s[0];
				}
			}
			if(cur==strlen(s))					//最后的输出有点问题
			{
				if(cnt!=1)
					cout<<cnt<<str[0];
				else if(0==strcmp("11",str))
					cout<<"11";
				else if(strlen(str)>=1)		//还有不重复的字符串,但最后可能是一个字符 strlen(str) > 1
					cout<<"1"<<str<<"1";
			}
		
		}
		cout<<endl;
	}
    return 0;
}