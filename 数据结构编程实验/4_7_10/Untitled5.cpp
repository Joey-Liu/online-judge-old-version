#include <iostream>
#include <string>
#define SIZE 1010
using namespace std;

int num=1;
int n=0;
int main()
{
    cin>>n;
    while(n--)
    {
        int mark[SIZE]={0};
        int na,nb,nc;
        string la,lb,lc;
        cin>>la>>lb>>lc;
        na=la.length();
        nb=lb.length();
        nc=lc.length();
        
        int search1,search2;
        search1=search2=0;
        
        bool flag1,flag2;
        flag1=flag2=true;
        
        for(int i=0;i<na+nb;i++)
        {
            if(la[search1]==lc[i])
            {
                search1++;
                mark[i]=1;
            }
        }
        if(search1!=na)
            flag1=false;
        
        for(int i=0;i<na+nb;i++)
        {
            if(1==mark[i])
                continue;
            if(lb[search2]==lc[i])
            {
                search2++;
                mark[i]=1;
            }
        }       
        if(search2!=nb)
            flag2=false;
        
        cout<<"Data set "<<num<<":";
        if(flag1 && flag2)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        num++;
    }
    system("pause");
    return 0;
}
        
