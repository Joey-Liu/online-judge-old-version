#include <iostream>
#include <stdio.h>

using namespace std;
const int maxn = 50 + 30;
int bricks[maxn], n, avg, res;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kase = 0;
    bool flag = true;
    while(cin >> n && n)
    {
        flag = false;
        avg = 0;
        res = 0;
        for(int i = 0;i < n;i++)
        {
             cin >> bricks[i];
             avg += bricks[i];
        }
        avg /= n;
        for(int i = 0;i < n;i++)
        {
            if(bricks[i] < avg)
                res += avg - bricks[i];
        }
        cout<<"Set #"<<++kase<<endl;
        cout<<"The minimum number of moves is "<<res<<"."<<endl<<endl;
    }
    return 0;
}
