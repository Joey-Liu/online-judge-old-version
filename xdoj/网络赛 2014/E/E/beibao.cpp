#include <iostream>
#include <memory.h>
using namespace std;
const int max_money = 2000 + 100;
const int max_book = 2000 + 100;

int Book[max_book];
int MaxMonoy[max_money][max_book];

int GetMaxGold(int money,int minenum)
{
	int retmax;
	if(-1 != MaxMonoy[money][minenum])
		retmax = MaxMonoy[money][minenum];
	else if(0==minenum)//到最后的选择
	{
		if(money >= Book[minenum])
		{
			retmax = Book[minenum];
		}
		else
			retmax = 0;
	}
	else if(money >= Book[minenum])//分析买或不买
	{
		retmax = max(Book[minenum] + GetMaxGold(money - Book[minenum],minenum - 1),GetMaxGold(money,minenum - 1));
	}
	else//不购买
	{
		retmax = GetMaxGold(money,minenum - 1);
	}

	MaxMonoy[money][minenum] = retmax;
	return retmax;
}

int main()
{
	int realmoney;
	while(cin>>realmoney)
	{
		memset(MaxMonoy,-1,sizeof(MaxMonoy));
		memset(Book,0,sizeof(Book));
		int kind;
		cin>>kind;
		for(int i =0;i < kind;i++)
			cin>>Book[i];

		cout<<GetMaxGold(realmoney,kind - 1)<<endl;
	}
	return 0;
}

