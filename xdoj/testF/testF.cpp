#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 10000 + 20;

struct coder
{
    char id[30];
    int rating;
};

coder c[maxn];

int cmp(const void * a,const void * b)
{
    coder* c1 = (coder* )a;
    coder* c2 = (coder* )b;
    
    if(c1->rating != c2->rating)
        return c2->rating - c1->rating;
    return (strcmp(c1->id, c2->id));
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int num;
    while(cin>>num)
    {
        memset(c,0,sizeof(c));
        for(int i = 0;i < num;i++)
            cin>>c[i].id>>c[i].rating;
        qsort(c,num,sizeof(coder),cmp);
        for(int i = 0;i < num;i++)
            cout<<c[i].id<<" "<<c[i].rating<<endl;
    }
    return 0;
}
