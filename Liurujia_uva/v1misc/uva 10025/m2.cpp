#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
const int maxn = 0x3fffffff;
long long int kase;
long long int k;
bool flag = true;

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%lld", &kase);
    while(kase--)
    {
        scanf("%lld", &k);
        if(k < 0)
            k = -k;
        if(!flag)
            printf("\n");
        flag = false;
        long long int sum = 0;
        long long int i = 0;
        for(i =0;;i++)
        {
            sum += i;
            if(sum >= k && (sum - k) % 2 == 0)
            {
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}
