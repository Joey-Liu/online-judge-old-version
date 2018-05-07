#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 30000 + 50;
struct stuff
{
	int id;
	int salary;
	int height;
}stu[maxn];

int cmp(const void* a,const void* b)
{
	stuff* _a = (stuff*)a;
	stuff* _b = (stuff*)b;
	return (_b->salary - _a->salary);
}

int parent[maxn];
int bro[maxn];
int son[maxn];
int sub[maxn];

int main()
{
	freopen("d.in","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		int stufnum,quesnum;//Ա����,��ѯ��
		scanf("%d %d",&stufnum,&quesnum);
		for(int i = 0; i < stufnum;i++)
			scanf("%d %d %d",&stu[i].id,&stu[i].salary,&stu[i].height);
		qsort(stu,stufnum,sizeof(stu[0]),cmp);

		memset(parent,0,sizeof(parent));
		memset(bro,0,sizeof(bro));
		memset(son,0,sizeof(son));
		memset(sub,0,sizeof(sub));

		//ͳ�Ƹ������ ��ĸ���
		for(int i = 1;i < stufnum;i++)
		{
			///Ѱ��i ���ڵ� j
			for(int j = i -1;j >= 0;j--)
			{
				if(stu[j].height >= stu[i].height)
				{
					parent[i] = j;
					bro[i] = son[j];
					son[j] = i;
					break;
				}
			}
		}

		//ͳ����������
		for(int i = stufnum - 1;i >= 0;i--)
		{
		//	int person = 0;//person����
			int tmson = son[i];
			for(;tmson != 0;tmson = bro[tmson])
			{
				sub[i] += 1 + sub[tmson];
			}
		}

		//����ѯ��
		int tmpid;
		int bigid = stu[0].id;
		for(int i = 0;i < quesnum;i++)
		{
			//cin>>tmpid;
			scanf("%d",&tmpid);
			for(int j = 0;j < stufnum;j++)
			{
				if(bigid==tmpid)
				{
					//cout<<"0 "<<sub[0]<<endl;
					printf("0 %d\n",sub[0]);
					break;
				}
				if(stu[j].id==tmpid)
				{
					//cout<<stu[parent[j] ].id<<" "<<sub[j]<<endl;
					printf("%d %d\n",stu[parent[j] ].id,sub[j]);
					break;
				}
			}
		}// for question
	}//casenum
	return 0;
}