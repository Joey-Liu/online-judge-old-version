#include <iostream>
#include <memory.h>
#include <string>
#include <map>
using namespace std;

const int maxn = 250;
bool t[maxn][maxn];//����ͼ (���ݱհ�)
map<string,int> ele;//��Դ Y
map<int,string> eqp;//�õ��豸 X
int ele_num;//��Դ����
int eqp_num;//�豸����
int res;//�����ӵ�����豸��

string names[maxn];
int nnames = 0;

int findname(string name)
{
	for(int i = 0;i < nnames;i++)
		if(name==names[i])
			return i;
	names[nnames++] = name;
	return nnames - 1;
}

int pre[maxn];
bool vis[maxn];

void Warshall(int tmp_t[maxn][maxn])//���㴫�ݱհ�
{
	int tmp = maxn - 1;

	for(int k = 0;k <= tmp;k++)
		for(int i = 0;i <= tmp;i++)
			for(int j = 0;j <= tmp;j++)
				tmp_t[i][j] |= tmp_t[i][k] & tmp_t[k][j];

}


void init()
{
	int index = 1;
	string str;
	cin>>ele_num;
	for(int i = 0;i < ele_num;i++)
	{
		cin>>str;
		ele[str] = index++;
	}

	index = 1;
	cin>>eqp_num;
	for(int i = 0;i < eqp_num;i++)
	{
		cin>>str>>str;
		eqp[index++] = str; 
	}
}


void mkmap()
{
	memset(t,false,sizeof(t));

	for(int i = 1;i <= eqp_num;i++)//ö�ٸ����豸
	{
		for(map<string,int>::iterator it = ele.begin();it != ele.end();it++)//ö�ٸ�����Դ
		{
			if(eqp[i]==(*it).first)
				t[i][(*it).second] = true;
		}//for it
	}//int i

	int tmp_t[maxn][maxn];//���ݱհ�
	memset(tmp_t,false,sizeof(tmp_t));
	int transler;
	string s1,s2;//�õ��豸������
	//cin>>transler;
	/*
	while(transler--)
	{
		bool flag = false;
		cin>>s1>>s2;
		for(map<string,int>::iterator it = ele.begin();it != ele.end();it++)
		{
			for(int i = 1;i <= eqp_num;i++)//�õ��豸
			{
				if((*it).first==s2 && eqp[i]==s1)
				{
					tmp_t[i][(*it).second] = true;
					flag = true;
				}
				if(flag)
					break;
			}//int i
			if(flag)
				break;
		}//map
	}//while
	
	Warshall(tmp_t);
	for(int i = 1;i <= eqp_num;i++)
		for(int j = 1;j <= ele_num;j++)
		{
			t[i][j] |= tmp_t[i][j];
		}
	*/
	cin>>transler;
	while(transler--)
	{
		cin>>s1>>s2;
		int a = findname(s1);
		int b = findname(s2);
		tmp_t[a][b] = true;
	}
	Warshall(tmp_t);

	//��t���������ӱ�
	int num1,num2;
	for(int i = 0;i < nnames;i++)//ö�ٸ������
	{
		num1 = -1;num2 = -1;
		//��һ���������Ӧ����,���������������һ�����
		for(map<int,string>::iterator it = eqp.begin();it != eqp.end();it++)
		{
			if((*it).second==names[i])
			{
				num1 = (*it).first;
				map<string,int>::iterator it;
				for(int j = 0;j < nnames;j++)
				{
					if(tmp_t[i][j])
					{
					//it = ele.find(names[j]); has some problems..
						for(it = ele.begin();it != ele.end();it++)
						{
							if((*it).first==names[j])
								t[num1][(*it).second] = true;
						}
			//			if(it != ele.end())
			//		{
			//			num2 = (*it).second;
			//			t[num1][num2] = true;
			//		}
					}
				}
				//break;
			}
		}
		if(num1==-1)
			continue;
		/*
		map<string,int>::iterator it;
		for(int j = 0;j < nnames;j++)
		{
			if(tmp_t[i][j])
			{
				//it = ele.find(names[j]); has some problems..
				for(it = ele.begin();it != ele.end();it++)
				{
					if((*it).first==names[j])
						t[num1][(*it).second] = true;
				}
		//		if(it != ele.end())
		//		{
		//			num2 = (*it).second;
		//			t[num1][num2] = true;
		//		}
			}
		}
		if(num2==-1)
			continue;

	//	t[num1][num2] = true;
     	*/
	}//for int i


	memset(pre,0,sizeof(pre));
}

bool dfs(int i)//ö���õ��豸
{
	for(int j = 1;j <= ele_num;j++)
	{
		if(!vis[j] && t[i][j])
		{
			vis[j] = true;
			if(pre[j]==0 || dfs(pre[j]))
			{
				pre[j] = i;
				return true;
			}
		}
	}
	return false;
}

void solve()
{
	res = 0;
	for(int i = 1;i <= eqp_num;i++)
	{
		memset(vis,false,sizeof(vis));
		if(dfs(i))
			res++;
	}
}

int main()
{
	freopen("C.9.dat","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	mkmap();
	solve();
	cout<<eqp_num - res<<endl;
	return 0;
}