#include <iostream>
#include <stdio.h>
using namespace std;

int cal_height(int level,int* height1)
	//level�����޸�ԭ���߶�height1��   ��������ֵΪת��������߶�
{
	char c;
	int n;//nΪ��ǰ����ӽڵ����
	int height = 0;//ת�������߶�
	if(level > *height1)//��ǰ����Ѿ��������ߣ������ԭ���߶�
		*height1 = level;

	int tmp;
	for(n = 0;(c = getchar() )=='d';n++)//�����ֵܽڵ�ת����Ϊ�Ҷ��ӽڵ㣬������n++��������ߵ���
		//Ŀǰd�ĸ���Ϊn+1�����ýڵ�λ�ڸ�������n+1��
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
