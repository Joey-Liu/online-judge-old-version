#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;
const int maxn = 1000 + 10;

struct node
{
    int speed;
    int weight;
    int id;
} mice[maxn];

int cmp(const void *a,const void *b)
{
    node *c = (node *)a;
    node *d = (node *)b;
    
    if(c->weight != d->weight)
        return c->weight - d->weight;
    return d->speed - c->speed;
}

int dp[maxn];
int parent[maxn];
int num;


void disp(int index)
{
    if(-1 == parent[index])
        cout<<mice[index].id<<endl;
    else
    {
        disp(parent[index]);
        cout<<mice[index].id<<endl;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int w,s;
    num = 0;
    while(cin>>w>>s)
    {
        mice[num].weight = w;
        mice[num].speed = s;
        mice[num].id = num;
        num++;
    }
    
    qsort(mice, num, sizeof(node), cmp);
    for(int i = 0;i < maxn;i++)
        dp[i] = 1;
    memset(parent,-1,sizeof(parent));
    
    for(int i = 1;i < num;i++)
    {
        for(int j = 0;j < i;j++)
        {
            if(mice[j].weight > mice[i].weight && mice[j].speed < mice[i].speed)
            {
                if(dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }// if
        } //for int j
    }// for int i
    
    int ans = -1,index = -1;
    for(int i = 0;i < num;i++)
    {    
        if(ans < dp[i])
        { 
            ans = dp[i];
            index = i;
        }    
    }
    
    cout<<ans<<endl;
    disp(index);
    
    return 0;
}





