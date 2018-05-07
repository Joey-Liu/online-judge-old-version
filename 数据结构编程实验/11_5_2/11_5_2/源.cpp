#include <iostream>
#include <string>
using namespace std;

//据说数据不会很大
const int maxn_map = 1000;//总结点个数
const int maxn = 100;

int mt[maxn][maxn];//表格矩阵
short map[maxn_map][maxn_map];//连接关系矩阵
bool has[maxn_map];
int pre[maxn_map];

int queue[maxn_map];
int tot;//拓扑排序队尾指针


int trans(const string & str)
{
	int res = 0;
	for(int i = 0;i < str.size();i++)
		res = res *10 +  (str[i] - '0');
	
	return res;
}


void createmap(const string & str,int row,int col)//构造指向 (row,col) pos 的关系 , row col is i and j ,so we need a little change
{
	int pos = col * maxn + (row + 1);//目标结点
	has[pos] = true;
	for(int i = 1;i < str.size();)//处理整个表达式
	{
		int pos_col = 0,pos_row = 0;//坐标换算后的行列位置(col --)
		for(;(str[i] != '+') && (i < str.size() );i++)//依次处理各个坐标
		{
			if(str[i] >= 'A' && str[i] <= 'Z')
				pos_col = pos_col * 26 + (str[i] - 'A'  + 1);
			else
				pos_row = pos_row * 10 + (str[i] - '0');
		}
		pos_col--;
		int posfrom = pos_col * maxn + pos_row;//结点位置
		has[posfrom] = true;
		map[posfrom][pos] = 1;
		pre[pos]++;

		i++;// "+"
	}
}

void kahn()//拓扑排序
{
	for(int i = 1;i < maxn_map;i++)
	{
		if(0==pre[i] && has[i])
			queue[tot++] = i;
	}

	for(int i = 0;i < tot;i++)
	{
		has[queue[i]] = false;
		for(int k = 1;k < maxn_map;k++)//删除关联的边，在相应节点上加上 数字
		{
			if(1==map[queue[i]][k])
			{
				//this has a big problem
//				mt[(k % (maxn + 1)) - 1][(k - 1) / 100] += mt[(queue[i] % (maxn +1)) - 1][(queue[i] - 1) / 100];
				int ti = k % maxn - 1;
				if(ti < 0)
					ti += 100;
				int tj = (k - 1)/100;

				int ri = queue[i] % maxn - 1;
				if(ri < 0)
					ri +=100;
				int rj = (queue[i] - 1)/100;

				mt[ti][tj] += mt[ri][rj];

				pre[k]--;
				if(0==pre[k] && has[k])
					queue[tot++] = k;
			}
		}//for int k
	}
}

void init(int col,int row)
{
	memset(mt,0,sizeof(mt));
	memset(map,0,sizeof(map));
	memset(pre,0,sizeof(pre));
	memset(queue,-1,sizeof(queue));
	memset(has,false,sizeof(has));

	string str;
	for(int i = 0;i < row;i++)
	{
		for(int j = 0;j < col;j++)
		{
			cin>>str;
			if(str[0] != '=')//输入为数字
			{
				mt[i][j] = trans(str);
				has[j * 100 + i + 1] = true;
			}
			else//构造有向图
			{
				createmap(str,i,j);
				mt[i][j] = 0;
			}
		}
	}//for int i
	
	tot = 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		int col,row;
		cin>>col>>row;
		init(col,row);
		kahn();
		for(int i = 0;i < row;i++)
		{	
			for(int j = 0;j < col;j++)
				cout<<mt[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}