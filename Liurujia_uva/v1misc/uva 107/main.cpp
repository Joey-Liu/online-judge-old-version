#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>

using namespace std;
double N, M, K, H, S, SH;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> H >> M)
    {
        if(!H && !M)
            break;

        N = 1;
        while(abs(log(M) / log(H) - log(N) / log(N + 1)) > 1e-10)
            N++;
        K = (int)(log(H) / log(N + 1) + 0.5);
        if(1 == N)
            S = K;
        else
            S = int((pow(N, K) - 1) / (N - 1) + 0.5);
        cout<<S<<' ';
        SH = int((1 - pow(N / (1 + N), K +1)) * H * (N + 1) + 0.5);
        cout<<int(SH)<<endl;
    }//while cin
    return 0;
}
