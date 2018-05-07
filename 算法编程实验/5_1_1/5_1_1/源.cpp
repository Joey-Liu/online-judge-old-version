#include <iostream>
using namespace std;

int t,n,k;//测试用例t，墙数n，最大穿墙数k
int x,y,x1,y2;
int max_x;
int max_y;
int sum_s;

const int maxn = 100 + 10;
int map[maxn][maxn];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(map,0,sizeof(map));
		max_x = max_y = sum_s = 0;
		scanf("%d%d",&n,&k);

		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d%d",&x,&y,&x1,&y2);
			//调整下地图范围
			if(x > max_x)
				max_x = x;
			if(x1 > max_x)
				max_x = x1;
			if(y > max_y)
				max_y = y;

			if(x < x1)
			{
				for(int j = x;j <= x1;j++)
					map[j][y] = i;
			}
			else
			{
				for(int j = x1;j <= x;j++)
					map[j][y] = i;
			}

		}//for
		for(int i = 0;i <= max_x;i++)
		{
			int tem = 0;//扫描第i列中的墙数
			for(int j = 0;j <= max_y;j++)
				if(map[i][j] > 0)
					tem++;
			int offset = tem - k;
			if(offset > 0)//需要拆除offset面墙
			{
				sum_s += offset;
				while(offset--)
				{
					int max_s = 0,max_bn;//max_s为向右最长墙的长度，max_bn为墙编号
					for(int k = 0;k <= max_y;k++)
					{
						if(map[i][k] > 0)//统计向右方同堵墙的格子数量
						{
							int tem_s = 0;
							for(int z = i + 1;z <= max_x;z++)
								if(map[z][k]==map[i][k])
									tem_s++;
								else
									break;
							if(max_s < tem_s)
							{
								max_s = tem_s;
								max_bn = k;
							}
						}
					}
					for(int a = i;a <= i + max_s;a++)
						map[a][max_bn] = 0;
				}//while offset
			}//if offset
		}//for i
		printf("%d\n",sum_s);
	}//while
	return 0;
}