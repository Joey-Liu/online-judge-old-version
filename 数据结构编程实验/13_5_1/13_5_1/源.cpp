#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

const int chess = 9;
int w[chess][chess][chess][chess];


bool position(int x,int y)
{
	if(x > 0 && x < chess && y >0 && y <chess)
		return true;
	return false;
}

void init()
{
	memset(w,-1,sizeof(w));
	for(int x = 1;x < chess;x++)
		for(int y = 1;y < chess;y++)
		{
			if(position(x + 1,y + 2))
				w[x][y][x + 1][y + 2] = 1;
			if(position(x + 2,y + 1))
				w[x][y][x + 2][y + 1] = 1;
			if(position(x - 1,y + 2))
				w[x][y][x - 1][y + 2] = 1;
			if(position(x -2,y +1))
				w[x][y][x -2][y +1] = 1;
			if(position(x + 1,y - 2))
				w[x][y][x + 1][y - 2] = 1;
			if(position(x + 2,y -1))
				w[x][y][x + 2][y - 1] = 1;
			if(position(x - 1,y - 2))
				w[x][y][x - 1][y - 2] = 1;
			if(position(x -2,y -1))
				w[x][y][x -2][y -1] = 1;
		}//for int y
		for(int kx = 1;kx < chess;kx++)
			for(int ky = 1; ky < chess;ky++)
				for(int ix = 1;ix < chess ;ix++)
					for(int iy = 1;iy < chess;iy++)
						for(int jx = 1;jx < chess;jx++)
							for(int jy = 1;jy < chess;jy++)
							{
								if(w[ix][iy][jx][jy] > w[ix][iy][kx][ky] + w[kx][ky][jx][jy] && w[ix][iy][kx][ky] >0 && w[kx][ky][jx][jy] > 0)
										w[ix][iy][jx][jy] = w[ix][iy][kx][ky] + w[kx][ky][jx][jy];						
								else if(-1==w[ix][iy][jx][jy] && w[ix][iy][kx][ky] >0 && w[kx][ky][jx][jy] > 0 )
									w[ix][iy][jx][jy] = w[ix][iy][kx][ky] + w[kx][ky][jx][jy];
							}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string s1,s2;
	int res;
	init();
	while(cin>>s1>>s2)
	{
		int x,y,m,n;
		x = s1[0] - 'a' + 1;
		y = s1[1] - '0';
		m = s2[0] - 'a' + 1;
		n = s2[1] - '0';

		if(x==m && y==n)
			res = 0;
		else
			res = w[x][y][m][n];
		cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<res<<" knight moves."<<endl;
	}
	return 0;
}