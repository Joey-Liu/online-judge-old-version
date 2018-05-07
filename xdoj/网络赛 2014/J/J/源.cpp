#include <iostream>
#include <math.h>
using namespace std;

void majiang(int fu,int fan_num,int player,
			int win,int place)
{

	int base = 0;
	base = fu * ( pow(2,fan_num + 2) );
	if(fan_num <= 5)
	{
		if(base > 2000)
			base = 2000;
	}
	else if(6==fan_num || 7==fan_num || 8==fan_num)
	{
		base = 3000;
	}
	else if(9==fan_num || 10==fan_num)
	{
		base = 4000;
	}
	else if(11==fan_num || 12==fan_num)
	{
		base = 6000;
	}
	else
	{
		base = 8000;
	}

	if(0==player)//庄家
	{
		if(0==win)//庄家自摸,输出闲家支付点数
		{
			int xianj = base * 2;
			xianj += place * 100;
			if(0 != xianj % 100)
			{
				xianj = xianj / 100;
				xianj = xianj *100 +100;
			}
			cout<<xianj;
		}
		else if(1==win)//庄家融合，输出放充着支付点数
		{
			int xianj_fa = base * 6;
			xianj_fa += place * 300;
			if(0 != xianj_fa % 100)
			{
				xianj_fa = xianj_fa /100;
				xianj_fa = xianj_fa*100 + 100;
			}
			cout<<xianj_fa;

		}
	}
	else if(1==player)//闲家
	{
		if(0==win)//现价自摸
		{
			int xian,zhuang;
			xian = base;
			zhuang = base * 2;
			
			xian += place * 100;
			zhuang += place * 100;

			if(0 != xian % 100)
			{
				xian = xian/100;
				xian = xian*100 + 100;
			}
			if(0 !=zhuang % 100)
			{
				zhuang = zhuang/100;
				zhuang = zhuang*100 +100;
			}
			cout<<xian<<" "<<zhuang;
		}
		else if(1==win)//闲家融合
		{
			int fang = base * 4;
			fang += place*300;
			if(0 != fang %100)
			{
				fang = fang/100;
				fang = fang*100 + 100;
			}
			cout<<fang;
		}
	}
}

int main()
{
	int a,b,c,d,e;
	while(cin>>a)
	{
		cin>>b>>c>>d>>e;
		majiang(a,b,c,d,e);
		cout<<endl;
	}
	return 0;
}
