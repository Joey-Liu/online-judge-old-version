#include <iostream>
#include <string.h>
using namespace std;

const int maxw=10000+10;
const int maxt=1000000+10;

int suffix[maxw];				//next 
void next(char  w[])
{
	suffix[0]=-1;
	suffix[1]=0;
	int k=0;
	for(int i=2;i<=strlen(w);i++)
	{
		while(k>=0 && w[k]!=w[i-1])
			k=suffix[k];
		suffix[i]=++k;
	}
}

int match(char w[],char s[])
{
	int cnt=0;
	int wlen=strlen(w);
	int slen=strlen(s);
	int p=0,cur=0;				//w”Îsµƒ÷∏’Î
	while(cur<slen)
	{
		if(w[p]==s[cur])
		{
			p++;
			cur++;
		}
		else if(p>=0)
			p=suffix[p];
		else
		{
			cur++;
			p=0;
		}
		if(p==wlen)
		{
			cnt++;
//			p--;					//should be this
			p=suffix[p];
		}
	}
	return cnt;
}

int main()
{
	int loop;
	cin>>loop;
	while(loop--)
	{
		char w[maxw],t[maxt];
		cin>>w;
		cin>>t;
		next(w);
		for(int i=0;i<=strlen(w);i++)
			cout<<suffix[i]<<"    ";
		cout<<endl;
		cout<<match(w,t)<<endl;
	}
	return 0;
}





