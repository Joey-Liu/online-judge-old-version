
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE  100
#define SIZE 80
typedef struct{
    int base;
    int top;
    char* stack;
}Sqstack;

void InitStack(Sqstack &S)
{
     S.stack=(char*)malloc(sizeof(char)*MAXSIZE);
     if(!S.base){
         printf("内存不足!\n");
         exit(0);
     }
     S.top=-1;
}


void Push(Sqstack &S,char e)
{
     /*if(S.top-S.base==0){
         S.base=(char*)realloc(S.base,2*MAXSIZE*sizeof(int));
         if(!S.base){
             printf("内存不足!\n");
             exit(0);
         }
         S.top=S.base+S.stacksize;
         S.stacksize=2*S.stacksize;
     }*/
     S.top++;
     S.stack[S.top]=e;
}


char Pop(Sqstack &S)
{
    if(S.top==-1){
        printf("栈为空，无法删除!\n");
        system("pause");
        exit(1);
    } 
    S.top--;
    return S.stack[S.top+1];
} 


int StackEmpty(Sqstack S)
{
    if(S.top==-1)
        return 1;
    else
        return 0;
}


int Gettop(Sqstack S)
{
    if(S.top==-1){
        printf("栈为空，无元素!\n");
        system("pause");
		exit(1);
    }
    return S.stack[S.top];
}
