#include <iostream>
#include <string>

using namespace std;
const int maxn = 30;


void preorder(string* leaves,int levels)//levels 为递归元素层数
{
	while(levels > 0 && leaves[levels - 1].size()==0)//因为左右子树长度和不一样
		levels--;
	////////////////////////////////////////
	levels--;//回到最后一行
	if(levels < 0)
		return ;
	char root = leaves[levels][0];
	if(0==levels)
	{
		cout<<root;
		return;//结束调用;
	}
	string* left = new string[levels];
	string* right = new string[levels];//左右儿子序列
	for(int i = 0;i < levels;i++)
	{
		int pos = 0;
		while(pos < leaves[i].size())
		{
			if(leaves[i][pos] > root)
				break;
			else
				pos++;
		}//pos 为右儿子起始位置
		left[i].assign(leaves[i],0,pos);
		//pos 若超尾则说明没有右儿子
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
	int num = 0;//树层数
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