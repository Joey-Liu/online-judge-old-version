#include <iostream>
#include <string.h>
using namespace std;
const int maxm=10+5;
const int maxs=60+5;
int main()
{
//	freopen("4.in.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int loop=0;
	cin>>loop;

	while(loop--)
	{
		int m,j,i=0;			//i for count,j for end of string
		int len=0;						// for the length of the same string
		char p[maxm][maxs];
		char ans[maxs]="";			//ans

		cin>>m;
		for(i=0;i<m;i++)
			cin>>p[i];
		for(i=0;i < strlen(p[0]); i++)
		{
			char s[maxs];					    // for the same string
			//int len=0;						// for the length of the same string
			for(j=i+2;j < strlen(p[0]); j++)	//for every important string 
			{
				strncpy(s,p[0]+i,j-i+1);
				s[j-i+1]='\0';					//this one length is j-i+1

				bool ok=true;
				int k=1;
				for(k=1;k < m;k++)
				{
					if(NULL==strstr(p[k],s))
						ok=false;			// once,have a un_ok
				}
				if( (ok && j-i+1 > len) || ( ok && (j-i+1==len) && strcmp(s,ans) < 0) )		//the new same string
				{
					strcpy(ans,s);
					len=j-i+1;
				}
			}
		}
		if(len < 3)
			cout<<"no significant commonalities";
		else
			cout<<ans;
		cout<<endl;
	}
	return 0;
}
