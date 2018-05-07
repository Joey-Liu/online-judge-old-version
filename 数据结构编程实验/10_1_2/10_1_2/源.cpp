#include <iostream>
#include <string>

using namespace std;
const int maxn = 30;


void preorder(string* leaves,int levels)//levels Ϊ�ݹ�Ԫ�ز���
{
	while(levels > 0 && leaves[levels - 1].size()==0)//��Ϊ�����������ȺͲ�һ��
		levels--;
	////////////////////////////////////////
	levels--;//�ص����һ��
	if(levels < 0)
		return ;
	char root = leaves[levels][0];
	if(0==levels)
	{
		cout<<root;
		return;//��������;
	}
	string* left = new string[levels];
	string* right = new string[levels];//���Ҷ�������
	for(int i = 0;i < levels;i++)
	{
		int pos = 0;
		while(pos < leaves[i].size())
		{
			if(leaves[i][pos] > root)
				break;
			else
				pos++;
		}//pos Ϊ�Ҷ�����ʼλ��
		left[i].assign(leaves[i],0,pos);
		//pos ����β��˵��û���Ҷ���
		if(pos==leaves[i].size())
			right[i].clear();
		else
			right[i].assign(leaves[i],pos,leaves[i].size() - pos);
	}
	cout<<root;
	preorder(left,levels);
	preorder(right,levels);
}

int main()
{
	freopen("leaves.in","r",stdin);
	freopen("out.txt","w",stdout);
	int num = 0;//������
	string str[maxn];
	while(cin>>str[num])
	{
		if("*"==str[num])
		{
			preorder(str,num);
			cout<<endl;
			num = 0;
		}
		else if("$"==str[num])
		{
			preorder(str,num);
			return 0;
		}
		else
			num++;
	}
	return 0;
}