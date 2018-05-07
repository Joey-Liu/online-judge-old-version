#include<iostream>
#include<stdlib.h>
#include<string>
#include"ջ�Ļ�������.h"
using namespace std;
void Change(string &s1,string &s2);
	int Precedence(char op);
int main()
{
	string s1,s2;					//s1Ϊ��׺��s2Ϊ��׺
	cout<<"please";
	cin>>s1;
    Change(s1,s2);
	cout<<s2<<endl;
	system("pause");
	return 0;
}


void Change(string &s1,string &s2)
{
	Sqstack R;
	int i=0,j=0;
	char ch;
	InitStack(R);
	Push(R,'@');				//@Ϊ��С���ȼ�
	ch=s1[i];
	while(ch!='\0')
	{
		if(' '==ch)  
			ch=s1[++i];		//�ո��ַ�������
		else if('('==ch)
		{
			Push(R,ch);
			ch=s1[++i];
		}
		else if(')'==ch)
		{
			while(Gettop(R)!='(')
				s2[j++]=Pop(R);
			Pop(R);						//����ջ��
			ch=s1[++i];
		}
		else if('+'==ch||'-'==ch||'*'==ch||'/'==ch)
		{	
			char w=Gettop(R);
			while(Precedence(w)>=Precedence(ch))
			{
				s2[j++]=w;
				Pop(R);
				w=Gettop(R);
			}
			Push(R,ch);
			ch=s1[i++];
		}
		else						//֮���Ӧ�������ֻ�С����
		{
			if((ch<'0'||ch>'9')&&ch!='.')
			{
				cout<<"���ӣ�����"<<endl;
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
			cout<<"��������"<<endl;
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

