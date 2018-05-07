#include <iostream>
#define SIZE 40
using namespace std;
int main()
{
    int n;
    int a[SIZE]={0};
    cin>>n;
    for(int i=0;i<n+1;i++)
        cin>>a[i];
    if(n>=3)
        cout<<"NO";
    else if(n < 2)
        cout<<"YES";
    else
    {
        if(a[1]*a[1]-4*a[0]*a[2]>=0)
            cout<<"NO";
        else
            cout<<"YES";
    }
    return 0;
}
        
               
