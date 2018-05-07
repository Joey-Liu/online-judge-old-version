#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int maxn = 1000 + 100;//两行单词数量
struct info
{
	string word[1024];//基于1
	int num;
}f1,f2;
string str;

bool init()
{
	f1.num = 0;
	f2.num = 0;

//	string str;
//	getline(cin,str);
	if(str.empty())
		return false;
	for(int i = 0;i < str.size();i++)
		if((str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z') || str[i]==' ')
			continue;
		else
			str[i] = ' ';

	istringstream ss(str);
	string tmp;
	while(ss>>tmp)
	{
		f1.num++;
		f1.word[f1.num] = tmp;
	}

	getline(cin,str);
	if(str.empty())
		return false;
	for(int i = 0;i < str.size();i++)
		if((str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z') || str[i]==' ')
			continue;
		else
			str[i] = ' ';

	istringstream ss2(str);
	while(ss2>>tmp)
	{
		f2.num++;
		f2.word[f2.num] = tmp;
	}

	return true;
}

int c[maxn][maxn];

void LCS()
{
	memset(c,0,sizeof(c));
	int m = f1.num;
	int n = f2.num;
	for(int i = 1;i <= m;i++)
		c[i][0] = 0;
	for(int i = 1;i <= n;i++)
		c[0][i] = 0;

	for(int i = 1;i <= m;i++)
	{
		for(int j =1;j <= n;j++)
		{
			if(f1.word[i]==f2.word[j])
				c[i][j] = c[i -1][j -1] + 1;
			else if(c[i -1][j] >= c[i][j -1])
				c[i][j] = c[i - 1][j];
			else
				c[i][j] = c[i][j - 1];
		}
	}//for int i
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum = 1;
	while(getline(cin,str))
	{
		if(!init())
			cout<<casenum++<<".BLANK!"<<endl;
		else
		{
			LCS();
			cout<<casenum++<<".Length of longest match: "<<c[f1.num][f2.num]<<endl;
		}
	}
	return 0;
}