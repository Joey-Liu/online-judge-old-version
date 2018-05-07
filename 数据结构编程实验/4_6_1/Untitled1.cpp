#include <iostream>
#include <cstring>
using namespace std;
#define MAXM 15
#define MAXS 65
int main()
{
	freopen("in.txt","r",stdin);
	freopen("output.txt","w",stdin);
    int loop;
    cin>>loop;
    while(loop--)
    {
        int m;
        char p[MAXM][MAXS];
        
        cin>>m;
        for(int i=0;i<m;i++)
            cin>>p[i];
        int len=0;            //最长子串长度
        char ans[MAXS];
        for(int i=0;i<strlen(p[0]);i++)
        {
            for(int j=2+i;j<strlen(p[0]);j++)
            {
                char s[MAXS];
                strncpy(s,p[0]+i,j-i+1);
                s[j-i+1]='\0';
                bool ok=true;
                for(int k=1;k<m && ok;k++)
                {
                    if(NULL==strstr(p[k],s))
                        ok=false;
                }
                if(ok && (j-i+1 >len || j-i+1==len && strcmp(ans,s)>0))
                {
                    len=j-i+1;
                    strcpy(ans,s);
                }
            }//for
        }//for
    if(len<3)
        cout<<"no significant commonalities" <<endl;
    else   
        cout<<ans<<endl;
    }
    return 0;
}                      
