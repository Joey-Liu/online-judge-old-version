
#include<iostream>
using namespace std;
int main()
{
long int i,j,p[100000]={0},a[100000]={0};
long k =-1;
 for(i=1;i<=100000;i++)
    a[i]=i+1;
for(i=0;i<=100000;i++)
{
    if(a[i]!=0)
       p[++k]=a[i];
	for(j=i+1;j<=100000;j++)                      //k+1 -> i+1
    {
     if(a[j]%p[k]==0)
        a[j]=0;
    }
}

for(i=0;i<=k;i++)
{
	cout<<p[i]<<endl;
}
system("pause");
return 0;
}
