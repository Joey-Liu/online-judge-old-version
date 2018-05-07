#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

const int maxn = 150;
int hashsetFir[maxn][maxn];
int hashsetSec[maxn][maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string str;
    while(cin>>str)
    {
        memset(hashsetFir, -1, sizeof(hashsetFir));
        memset(hashsetSec, -1, sizeof(hashsetSec));

        for(int i = 0; i < 6; i++)
        {
            hashsetFir[str[i]][str[5- i]]++;
            hashsetFir[str[5- i]][str[i]]++;
        }
        for(int i = 6; i < 12; i++)
        {
            hashsetSec[str[i]][str[17 - i]]++;
            hashsetSec[str[17 - i]][str[i]]++;
        }
        int index = 0;
        for(index = 0; index < 3; index++)
        {
            if(hashsetFir[str[index]][str[5-index]] != hashsetSec[str[index]][str[5-index]])
                break;
        }
        if(index == 3)
            cout<<"TRUE"<<endl;
        else
            cout<<"FALSE"<<endl;
    }
    return 0;
}
