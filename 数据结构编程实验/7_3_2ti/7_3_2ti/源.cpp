#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 250000;
struct player
{
	int id;							//δ�ϰ�� idΪ 0������idΪi��
	int p;
};
player a[maxn];
bool in[maxn];						//ȷ���Ƿ��ϰ�

bool cmp_p(const player &A,const player &B)
{
	return A.p > B.p;
}

bool cmp_id(const player &A,const player &B)
{
	return A.id < B.id;
}

int main()
{
	freopen("grandpa.in","r",stdin);
	freopen("output.txt","w",stdout);

//	memset(a,0,sizeof(a));
//	memset(in,false,sizeof(in));
	int n,m,temp;
	scanf("%d%d",&n,&m);
	while(n || m)
	{
		memset(a,0,sizeof(a));
		memset(in,false,sizeof(in));
		for(int i = 0;i < n*m;i++)
		{
			scanf("%d",&temp);
			if(!in[temp])
			{
				in[temp] = true;
				a[temp].id = temp;
				a[temp].p = 1;
			}
			else
				a[temp].p++;
		}
		sort(a,a + maxn,cmp_p);
		int k =0;
		for(k =2;k < maxn;)				//�Ҳ��еڶ�����Ӧ�þ��Ǵӵ�������ʼ��
		{
			if(a[k].p != a[1].p)
				break;
			k++;
		}
		k--;
		sort(a+1,a+k+1,cmp_id);		//������Ӧ����a+1��a+k+1,
		for(int j =1;j < k;j++)
		    printf("%d ",a[j].id);
		printf("%d \n",a[k].id);
		scanf("%d%d",&n,&m);
	}
	system("pause");
	return 0;
}

