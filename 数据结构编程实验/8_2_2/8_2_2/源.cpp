#include <stdio.h>
#include <memory.h>
const int maxn = 100000 + 100;

int set[maxn];//��¼ÿ��Ԫ�ص�ջ�ͣ�����Ԫ�أ�Ԫ��
int top[maxn];//��¼ÿ��Ԫ�ص�ջ��Ԫ��
int cnt[maxn];//j��¼ÿ��Ԫ�ص�ջ�͵�Ԫ�ظ���

int set_find(int p)//����Ԫ��p��ջ��Ԫ�أ�������·��ѹ���������� p ��ջ��Ԫ�صĸ���
{
	if(set[p] < 0)//����Ϊջ��Ԫ��
		return p;
	
	if(set[set[p] ] >= 0)//p��ջ��Ԫ��set[p]������������ջ��Ԫ�أ�Ҳ����˵p��ջ��Ԫ�����滹������Ԫ�أ�
	{
		int tmp = set[p];
		set[p] = set_find(tmp);//ѹ��·��
		cnt[p] += cnt[tmp];		//�ۼ� p ��ջ��Ԫ�ص�������ע��tmp���µ�ջ��Ԫ�ص����� �� set_join �������Ѿ�����	
	}
	return set[p];//����ջ��Ԫ��
}

void set_join(int x,int y)
{
	x = set_find(x);
	y = set_find(y);//x y ��Ϊ���Ե�ջ��Ԫ��

	set[x] = y;		//x ջ��Ԫ�ػ�Ϊ y 
	set_find(top[y]);//��֤top[y]��ջ��Ԫ�صĸ���(cnt[top[y] ])��ȷ
	cnt[x] = cnt[top[y] ] + 1; // ����x ����ջ��Ԫ�صĸ���
	top[y] = top[x]; //y ��ջ��Ԫ�ػ�Ϊx ջ��Ԫ�أ�ֻ�øı� ջ�� ����¼�� ջ��Ԫ�ؼ��� ��������Ҳ�ò�����
}

int main()
{
	freopen("cubes.10.in","r",stdin);
	freopen("out10.txt","w",stdout);
	memset(set,-1,sizeof(set));
	memset(cnt,0,sizeof(cnt));
	for(int i =0 ;i < maxn;i++)
		top[i] = i;

	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		char c;
		int a,b;
		
		getchar();
		scanf("%c",&c);
		if('M'==c)
		{
			scanf("%d%d",&a,&b);
			set_join(a,b);
		}
		else
		{
			scanf("%d",&a);
			set_find(a);//����a��ջ��Ԫ�صĸ���
			printf("%d\n",cnt[a]);
		}
	}
	return 0;
}