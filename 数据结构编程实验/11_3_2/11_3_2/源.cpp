#include <iostream>
using namespace std;

const int maxn = 30;
int map[maxn][maxn];//ͼ�ڽӾ���
bool tl[maxn];//�ɴ��Ծ��������ж��Ƿ������·
bool visited[maxn];//dfs ʱ�жϽ���Ƿ���ʹ�
int pre[maxn];//�����������

bool topo = true;//�Ƿ���Ҫ����
bool only = false;//���������Ƿ�Ψһ

void dfs(int n)//����n�� �ɴ��Ծ���
{
	tl[n] = true;
	visited[n] = true;
	for(int i = 0;i < maxn;i++)
	{
		if(1==map[n][i] && visited[i]==false)
			dfs(i);
	}
}


void solve(int num,int ques)//����ѯ������
{
	topo= true;
	only = false;
	//�ڽӾ��󣬿ɴ��Ծ����ʼ��
	memset(map,0,sizeof(map));
	memset(tl,0,sizeof(tl));
	memset(pre,0,sizeof(pre));

	char ch1,ch2,c;
	int relations = 0;
	for(int i = 0;i < ques;i++)
	{
		cin>>ch1>>c>>ch2;
		int m = ch1 - 'A';
		int n = ch2 - 'A';
		map[m][n] = 1;
		pre[n]++;
		
		memset(tl,false,sizeof(tl));
		memset(visited,false,sizeof(visited));
		
		//��n ��������
		dfs(n);
		//���ڷ����
		if(true==tl[m])
		{
			topo = false;//����Ҫ������������
			relations = i + 1;
			break;
		}

		//���Խ�����������,Q Ϊ�������� ����
		int Q[maxn];
		memset(Q,0,sizeof(Q));
		int tot = 0;//ͳ��ru����Ϊ��Ľ�㣬��βָ�룡������������������������
		for(int k = 0;k < num;k++)
			if(0==pre[k])
				Q[tot++] = k;

		if(tot==1)//ֻ��һ������Ϊ��Ľ��
		{
			//ʹ��ɾ�߷�
			only = true;//�п��ܲ���Ψһ��������
			int count = 0;//ͳ��ÿ������ ����Ϊ1 �Ľ����
			while(tot < num)
			{
				count = 0;
				//ע�� tot�ǳ�βָ��
				int tmpoint = Q[tot - 1];
				//ʹ��ɾ�߷���������������
				for(int k = 0;k < num;k++)
				{
					if(1==map[tmpoint][k])
					{
						//count++; ʧ��
						pre[k]--;
						if(0==pre[k])
						{
							Q[tot++] = k;
							count++;
						}
					}
				}//for 
				//��count > 1 �� �������в�Ψһ�����ü���ɾ�߷���ͬʱӦ�ý�ɾ���ı߻ָ�  ������һ��ϵ
				if(count > 1)
				{
					for(int i = 0;i < num;i++)
					{
						if(1==map[tmpoint][i])
							pre[i]++;
					}
					only = false;
					break;
				}
			}//while

			if(only && tot==num)//������Ψһ��������
			{
				cout<<"Sorted sequence determined after "<<i + 1<<" relations: ";
				for(int i = 0;i < num;i++)
					cout<<char('A' + Q[i]);
				cout<<"."<<endl;
				//�����ε���������� ��������һ����
				for(int bi = 0;bi < (ques - i - 1);bi++)
					cin>>ch1>>c>>ch2;
				break;
			}
			else //û�в���Ψһ������������ô�ָ�ɾ���ı�
			{
				memset(pre,0,sizeof(pre));
				for(int j = 0;j < num;j++)
					for(int k = 0;k < num;k++)
						if(1==map[j][k])
							pre[k]++;
			}
		}//if ֻ��һ������Ϊһ�Ľڵ�
		else//�ж������Ψһ�Ľ��������һ��ϵ
		{
			continue;
		}

	}//for��������һ��ϵ
	//���ڷ����
	if(!topo)
	{
		cout<<"Inconsistency found after "<<relations<<" relations."<<endl;
		for(int i = 0;i < ques -relations;i++)
			cin>>ch1>>c>>ch2;
	}
	else if(!only)
		cout<<"Sorted sequence cannot be determined."<<endl;
}


int main()
{
	freopen("B.1.dat","r",stdin);
	freopen("out.txt","w",stdout);
	int nu,qu;
	while(cin>>nu>>qu)
	{
		if(nu || qu)
			solve(nu,qu);
		else
			break;
	}
	return 0;
}