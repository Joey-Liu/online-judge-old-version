#include<iostream>
#include<stdio.h>
#include<stdlib.h>
typedef struct {
      char ch;
      unsigned int weight;
      unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;  
typedef char** HuffmanCode;
#define N 8
void  HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n,char d[]);
int main()
{
	int w[N]={5,29,7,8,14,23,3,11};
	char d[N+1]="abcdefgh";
	int i,n=8;
	i=1;
	HuffmanTree HT=NULL;
	HuffmanCode HC;
	HuffmanCoding(HT,HC,w,n,d);
	for(i=1;i<=n;i++)
		printf("%c:%s\n",HT[i].ch,HC[i]);
	
	system("pause");
	return 0;
}





void  HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n,char d[])			//w存放n个字符的权值
{
	if(n<=1)
	{
		printf("不用编码\n");
		system("pause");
		exit(1);
	}
	int m,i,j;				//一共n个叶子节点
	HuffmanTree p=NULL;
	m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
    for(i=1; i<=n; i++) 
	{
         HT[i].weight = w[i-1];
         HT[i].ch=d[i-1];
		 HT[i].parent = 0;
         HT[i].lchild = HT[i].rchild = 0;
    }
         HT[i].lchild = HT[i].rchild = 0;
	for(;i<=m; ++i) 
	{
         HT[i].parent = 0;
    }
	for(i=n+1;i<=m;i++)			//开始建哈夫曼树
	{
		int s1=0,s2;		    	//存储权值最小的两个数
		for(j=1;j<m;j++)
		{
			if(HT[j].parent==0&&0==s1)  {s1=j;continue;}
			if(HT[j].parent==0)    {s2=j;break;}
		}
		for(j=s2;j<i;j++)		//注意j<i
		{
			if(HT[j].parent==0)
			{
			    if(HT[j].weight<HT[s1].weight)
				{
					s2=s1;
					s1=j;
				}
				else if(HT[j].weight<HT[s2].weight)
					s2=j;
			}
		}//挑选出权值最小的两个节点
		//printf("s1=%d,s2=%d\n",s1,s2);							//
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;				
		//printf("i=%d,weight=%d\n",i,HT[i].weight);

	}

		

    HC=(char**)malloc((n+1)*sizeof(char*));
	char* cd=(char*)malloc(n*sizeof(char));
	cd[n-1]='\0';
	int start,f,c;
	for(i=1;i<=n;i++)
	{
   		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{	
			if(HT[f].lchild==c)		
				cd[--start]='0';
			else
				cd[--start]='1';
		}
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}
