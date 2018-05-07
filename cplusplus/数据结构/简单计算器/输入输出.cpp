#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"栈的基本操作.h"

int Precedence(char op);
using namespace std;
double Compute(char* str);
int main()
{
	void Change(char* s1,char* s2);
	char* s1=new char[100];					//s1为中缀，s2为后缀
	char* s2=new char[100];
	
	cout<<"please\n";
	cin>>s1;
    Change(s1,s2);
	//cout<<s2<<endl;
	cout<<"="<<Compute(s2)<<endl;
	
	
	system("pause");
	return 0;
}


void Change(char* s1,char* s2)
{
	Sqstack R;
	int i=0,j=0;
	char ch;
	InitStack(R);
	Push(R,'@');				//@为最小优先级
	ch=s1[i];
	while(ch!='\0')
	{
		if(' '==ch)  
			ch=s1[++i];		//空格字符不处理
		else if('('==ch)
		{
			Push(R,ch);
			ch=s1[++i];
		}
		else if(')'==ch)
		{
			while(Gettop(R)!='(')
				s2[j++]=Pop(R);
			Pop(R);						//闪出栈顶
			ch=s1[++i];
		}
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
		{	
			char w=Gettop(R);
			while(Precedence(w)>=Precedence(ch))
			{
				s2[j++]=w;
				Pop(R);
				w=Gettop(R);
			}
			Push(R,ch);
			ch=s1[++i];
		}
		else						//之后就应该是数字或小数点
		{
			if((ch<'0'||ch>'9')&&ch!='.')
			{
				cout<<"孩子，别逗了"<<endl;
				system("pause");
				exit(1);
			}
			while((ch>='0'&&ch<='9')||ch=='.')
			{
				s2[j++]=ch;
				ch=s1[++i];
			}
			s2[j++]=' ';
		}
	}
	ch=Pop(R);
	while(ch!='@')
	{
		if(ch=='(')
		{	
			cout<<"输入有误"<<endl;
			system("pause");
			exit(1);
		}
		else
		{
			s2[j++]=ch;
			ch=Pop(R);
		}
	}
	s2[j++]='\0';
}




int Precedence(char op)
{
	switch(op)
	{
	 case '+':
	 case '-':
	   	 return 1;
	 case '*':
	 case '/':
		return 2;
	 case '(':
	 case '@':
	 default:
		return 0;
	}
}




double Compute(char* str)
{
	Sqstack S;
	double x,y;
	int i=0;
	InitStack(S);
	while(str[i])
	{
		if(' '==str[i])  {i++; continue;}
		switch(str[i])
		{
		case '+':
			x=Pop(S)+Pop(S);
			i++;
			break;
		case '-':
			x=Pop(S);
			x=Pop(S)-x;
			i++;
			break;
		case '*':
			x=Pop(S)*Pop(S);
			i++;
			break;
		case '/':
			x=Pop(S);
			if(x!=0.0)
				x=Pop(S)/x;
			else
			{
				cout<<"0不能做除数！"<<endl;
				system("pause");
				exit(1);
			}
			i++;
			break;
		default:
			x=0;
			while(str[i]<=57&&str[i]>=48)
			{
				x=x*10+str[i]-48;
				i++;
			}
			if('.'==str[i])
			{
				double j=10.0;
				i++;
				y=0;
				while(str[i]<=57&&str[i]>=48)
				{
					y=y+(str[i]-48)/j;
					i++;
					j=j*10;
				}
				x=x+y;
			}
		}			//end of switch
		Push(S,x);
	}//while end
	if(StackEmpty(S))
	{
		printf("后缀表达式出错\n");
		system("pause");
		exit(1);
	}
	x=Pop(S);
	printf("%lf\n",x);
	if(StackEmpty(S))    return x;
	else
	{
		cout<<"后缀表达式出错2\n";
		system("pause");
		exit(1);
	}
}
