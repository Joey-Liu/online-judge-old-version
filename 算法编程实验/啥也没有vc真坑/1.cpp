#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//修改后的二分搜索，返回从后向前，第一个比target大的索引 
int bsearch(int *a, int s, int e,int target)
{
    while(s<=e)
    {
        int mid = s +(e-s)/2;
        if(a[mid]<=target)
        {
            s=mid+1;
        }
        else 
        {
            e = mid-1;
        }
    }
    return s;
}
int getMaxSub(int *a, int n)
{
    int *maxIndex = new int[n];
    int *maxV = new int[n];
    int len =1;
    maxV[0] = a[0];
    maxIndex[0]=0;
    for(int i=1; i <n; i++)
    {
        if(a[i]>maxV[len-1])
        {
            maxV[len]=a[i];
            maxIndex[len]=i;
            len++;
        }
        else
        {
            int pos = bsearch(maxV,0,len-1,a[i]);
            maxV[pos]= a[i];
            if(pos == len-1)
                maxIndex[pos]=i;
        }
    }

    for(int i=0;i<len;i++)
    {
        printf("%d\t",a[maxIndex[i]]);
    }
    printf("\n");
    return len;
} 

int main()
{	
    

    int a[]={
        7,5,4,2,3,5,6,1,5,8,9,10
    };
    int b[]={
        1, 5, 8, 3, 6, 7, 2, 9 
    };
    printf("The array is :\n");

    for(int i=0;i<12;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nThe max ascending array is:\n");
    printf("The length of max ascending array is :%d\n",getMaxSub(a,12));
    //getMaxSub(b,8);
    return 0;
}