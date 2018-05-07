#include <iostream>
#include <string>
#include <map>
#include <memory.h>
using namespace std;

const int maxn = 1000 + 10;
int layer[maxn];
int parent[maxn];
map<string,int> mhash;
int num = 0;
void solve(int i)
{
	string s1;
	getline(cin,s1,'\n');
	int tmp = s1.find_last_of(' ',s1.size()) - s1.find_first_of(' ',0) + 1;//统计层次
	if(0 !=i)
		s1.erase(0,tmp);//删除空格
	mhash[s1] = num++;//添加记录编号
	layer[num - 1] = tmp;//添加记录层次
	if(0==i)
		layer[num - 1] = 0;

	int pos = num - 2;//从上一条记录开始查找父节点,找第一个层次小于当前结点的 结点
	while(layer[num - 1] <= layer[pos] && pos >= 0)
		pos--;
	if(pos >= 0)
		parent[num - 1] = pos;
	else
		parent[num - 1] = -1;
}

bool judge(string s1,string s2,string s3)
{
	int n1 = mhash[s1];
	int n2 = mhash[s2];
	if("child"==s3)//n1 为 n2 的儿子
	{
		return parent[n1]== n2 ? true : false;
	}
	else if("parent"== s3)//n1 为 n2 的父亲
	{
		return parent[n2]==n1 ? true : false;
	}
	else if("sibling"==s3)
	{
		return parent[n1]==parent[n2] ? true : false;
	}
	else if("descendant"==s3)//n1 为 n2 的后代
	{
		while(n1 >= 0)//追溯到根节点
		{
			n1 = parent[n1];
			if(n1 == n2)
				break;
		}
		if(n1 >= 0)
		    return true;
		return false;
	}
	else//n1 是 n2 的祖先
	{
		while(n2 >= 0)
		{
			n2 = parent[n2];
			if(n1==n2)
				break;
		}
		if(n2 >= 0)
			return true;
		return false;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	while(n || m)
	{
		getchar();
		memset(layer,-1,sizeof(layer));
		memset(parent,-1,sizeof(parent));
		mhash.clear();
	
		for(int i = 0;i < n;i++)
			solve(i);
		string s1,s2,s3;
		for(int i = 0;i < m;i++)
		{
			cin>>s1;
			cin>>s3>>s3>>s3;
			cin>>s2>>s2;
			s2.erase(s2.end() - 1);
			if(judge(s1,s2,s3))
				printf("True\n");
			else
				printf("False\n");
		}
		printf("\n");
		cin>>n>>m;
	}//while
	return 0;
}