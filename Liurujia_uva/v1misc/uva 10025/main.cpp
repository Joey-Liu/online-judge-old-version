#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
int kase;
double k, n;
bool flag = true;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &kase);
    while(kase--)
    {
        scanf("%lf", &k);
        if(k < 0)
            k = -k;
        if(!flag)
            printf("\n");
        flag = false;
        if(k == 0)
        {
            printf("0\n");
            continue;
        }
        n = ceil((sqrt(1 + 8*k) - 1) / 2.0);
        while(n * n + n >= 2 * k)
            n--;
        n++;
        long long int diff = (n*n + n)/2 - k;
        if(0 == diff % 2)
        {
            printf("%.0lf\n", n);
            continue;
        }
        double ad = ceil((sqrt(1.0 + 8 * diff) - 1) / 2);
        printf("%.0lf\n", n+ad);
    }
    return 0;
}
