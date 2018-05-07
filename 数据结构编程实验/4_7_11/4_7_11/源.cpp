#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

const int maxn_max = 500 + 10;
typedef pair<string,string> Pair_one;
typedef pair<string,int> Pair_two;

int main()
{
	freopen("anagram.in","r",stdin);
	freopen("output.txt","w",stdout);
	map<string,string> wordset;
	map<string,int> wordcount;
	string str,temp;
	while(cin>>str)
	{
		temp = str;
		sort(temp.begin(),temp.end());
		wordset.insert(Pair_one(str,temp));
		wordcount[temp]++;
	}

	int maxn = 0;
	int count = 0;
	
	map<string,int>::iterator its;
	map<string,int>::iterator its_tmp;
	map<string,int>::iterator itg[maxn_max];
	map<string,string>::iterator it;
	while(true)
	{
		bool flag = false;
		int i = 1;
		maxn = 0;
		count++;
		for(its = wordcount.begin();its != wordcount.end();its++)
		{
			bool update = false;
			if(maxn < (*its).second)				//用小于号保证按字典顺序输出
			{
				maxn = (*its).second;
				temp = (*its).first;
				itg[0] = its_tmp = its;
				update = true;
			}
			else if(maxn==(*its).second && maxn != 0)
			{
				if(true==update)
				{
					i = 1;						//更新迭代器数组
				}
				itg[i++] = its;
				flag = true;								//出现多个单词重复次数相同
			}
		}
		if(0==maxn)						//第二个跳出循环条件
			break;			
	//	(*its_tmp).second = 0;			//将最大的重复单词数组置0
	//	cout<<"Group of size "<<maxn<<": ";
		///////////////////////////////////////////////////////////////////////
		string cmp = "";
	
		if(flag)
		{
			for(int j =0;j < i;j++)
			{
				for(it = wordset.begin();it != wordset.end();it++)
				{
					if((*itg[j]).first==(*it).second)				//找到第一个单词
					{
						temp = (*it).first;
						break;
					}
				}
				if(0==j)
				{
					cmp = temp;
				}
				else 
				{
					if(temp < cmp)
					{
						cmp = temp;
						its_tmp = itg[j];				//找到最单词后，同时保存其迭代器
					}
				}
			}
		}
		(*its_tmp).second = 0;
		cout<<"Group of size "<<maxn<<": ";
		
		temp = cmp;
		for(it = wordset.begin();it != wordset.end();it++)
		{
			if(temp==(*it).second)
			{
				cout<<(*it).first<<" ";
			}
		}
		cout<<".\n";
		if(5==count)					//第一个跳出循环条件
			break;
	}
	system("pause");
	return 0;
}
