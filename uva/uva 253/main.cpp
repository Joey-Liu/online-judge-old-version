#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>

using namespace std;
const int maxn = 30;
char str[maxn];
char fird[maxn], secd[maxn];
bool flag = false;
void rot_ver()
{
    char temp[maxn], res[maxn];
    memset(res, 0, sizeof(res));
    memset(temp, 0, sizeof(temp));
    strcpy(temp, secd);

    for(int i = 0; i < 4; i++)
    {
        res[0] = temp[0];
        res[5] = temp[5];

        res[1] = temp[3];
        res[2] = temp[1];
        res[3] = temp[4];
        res[4] = temp[2];
        if(!strcmp(res, fird))
        {
            flag = true;
            break;
        }
        strcpy(temp, res);
    }
}

void rot_x()
{
    char temp[maxn], res[maxn];
    memset(res, 0, sizeof(res));
    memset(temp, 0, sizeof(temp));
    strcpy(temp, secd);

    for(int i = 0; i < 4; i++)
    {
        res[1] = temp[1];
        res[4] = temp[4];

        res[0] = temp[2];
        res[2] = temp[5];
        res[3] = temp[0];
        res[5] = temp[3];
        if(!strcmp(res, fird))
        {
            flag = true;
            break;
        }
        strcpy(temp, res);
    }
}

void rot_y()
{
    char temp[maxn], res[maxn];
    memset(res, 0, sizeof(res));
    memset(temp, 0, sizeof(temp));
    strcpy(temp, secd);

    for(int i = 0; i < 4; i++)
    {
        res[2] = temp[2];
        res[3] = temp[3];

        res[0] = temp[4];
        res[1] = temp[0];
        res[4] = temp[5];
        res[5] = temp[1];
        if(!strcmp(res, fird))
        {
            flag = true;
            break;
        }
        strcpy(temp, res);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin>>str)
    {
        memset(fird, 0, sizeof(fird));
        memset(secd, 0, sizeof(secd));
        for(int i = 0; i < 6; i++)
            fird[i] = str[i];
        strcpy(secd, str + 6);
        flag = false;
        rot_ver();
        rot_x();
        rot_y();

        if(flag)
            cout<<"TRUE"<<endl;
        else
            cout<<"FALSE"<<endl;
    }
    return 0;
}
