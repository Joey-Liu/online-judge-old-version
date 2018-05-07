//from july csdn

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

void GetNext(char* p, int next[])
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]��ʾǰ׺��p[j]��ʾ��׺  
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}



//�Ż������next ������  
void GetNextval(char* p, int next[])  
{  
	int pLen = strlen(p);  
	next[0] = -1;  
	int k = -1;  
	int j = 0;  
	while (j < pLen - 1)  
	{  
		//p[k]��ʾǰ׺��p[j]��ʾ��׺    
		if (k == -1 || p[j] == p[k])  
		{  
			++j;  
			++k;  
			//��֮ǰnext�����󷨣��Ķ�������4��  
			if (p[j] != p[k])  
				next[j] = k;   //֮ǰֻ����һ��  
			else  
				//��Ϊ���ܳ���p[j] = p[ next[j ]]�����Ե�����ʱ��Ҫ�����ݹ飬k = next[k] = next[next[k]]  
				next[j] = next[k];  
		}  
		else  
		{  
			k = next[k];  
		}  
	}  
}  



int KmpSearch(char* s, char* p,int next[])
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen)
	{
		//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++      
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]      
			//next[j]��Ϊj����Ӧ��nextֵ        
			j = next[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}