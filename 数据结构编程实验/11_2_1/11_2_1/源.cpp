#include <iostream>
#include <string>
using namespace std;

int map[6][6];

void makemap()
{
	memset(map,0,sizeof(map));
	for(int i = 1;i <= 5;i++)
		for(int j = 1;j <= 5;j++)
			if(i != j)
				map[i][j] = 1;
	
	map[2][4] = map[4][2] = 0;
	map[1][4] = map[4][1] = 0;
}

void DFS(int i,int num,string str)//当num = 8时输出一个空格
{
	str += ('0' + i);
	if(9==num)
	{
		cout<<str<<endl;
		return;
	}
	for(int j = 1;j <=5;j++)
	{
		if(map[i][j])
		{
			map[i][j] = map[j][i] =0;
			DFS(j,num+1,str);
			map[i][j] = map[j][i] = 1;
		}
	}
}

int main()
{
	makemap();
	DFS(1,1,"");
	system("pause");
}
