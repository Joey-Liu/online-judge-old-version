#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int n;
string str;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin>>n;
    while(n--)
    {
        cin>>str;
        int len = str.size();
        if("1"== str || "4" == str || "78" == str)
            cout<<"+"<<endl;
        else if(str[len - 1] == '5' && str[len - 2] == '3')
            cout<<"-"<<endl;
        else if(str[0] == '9' && str[len - 1] == '4')
            cout<<"*"<<endl;
        else
            cout<<"?"<<endl;
    }
    return 0;
}
