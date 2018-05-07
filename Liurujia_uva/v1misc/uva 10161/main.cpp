#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int N;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin>>N && N)
    {
        int x = 1, y = 1;
        int m = sqrt(N);
        int shift = N - m * m;
        if(!shift)
        {
            if(0 == m % 2)
                x = m;
            else
                y = m;
        }
        else
        {
            if(m%2)
            {
                if(shift <= m + 1)
                {
                    y = m + 1;
                    x = shift;
                }
                else
                {
                    x=  m + 1;
                    int temp = shift - m - 1;
                    y = m +1- temp;
                }
            }
            else
            {
                if(shift <= m + 1)
                {
                    x= m + 1;
                    y = shift;
                }
                else
                {
                    y = m + 1;
                    int temp = shift - m - 1;
                    x = m + 1 - temp;
                }
            }
        }
        cout<<x<<" "<<y<<endl;
    }//while
    return 0;
}
