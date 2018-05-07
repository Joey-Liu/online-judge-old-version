#include <iostream>
#include <stdio.h>
using namespace std;

int cal_height(int level,int* height1)
	//level用来修改原树高度height1，   函数返回值为转换后的树高度
{
	char c;
	int n;//n为当前结点子节点个数
	int height = 0;//转换后树高度
	if(level > *height1)//当前层次已经大于树高，则更新原树高度
		*height1 = level;

	int tmp;
	for(n = 0;(c = getchar() )=='d';n++)//由于兄弟节点转换后为右儿子节点，所以用n++，完成树高递增
		//目前d的个数为n+1，即该节点位于该子树的n+1层
	{
		if( (tmp = cal_height(level + 1,height1) + n + 1) > height)
			height = tmp;
	}
	return height;
}

int main()
{
	freopen("graft.in","r",stdin);
	freopen("out.txt","w",stdout);
	int height1,height2,casenum = 1;
	char c;
	while((c = getchar()) != '#')
	{
		ungetc(c,stdin);
		height1 = 0;
		height2 = cal_height(0,&height1);
		printf("Tree %d: %d => %d\n",casenum++,height1,height2);
	}
	return 0;
}
