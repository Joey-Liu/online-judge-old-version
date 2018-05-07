#include <iostream>
using namespace std;

const int maxn = 105;
struct task
{
	int pro;
	bool iswork;
}Q[maxn];
int st,ed;//������βָ��

int main()
{
	freopen("printerqueue.in","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		int num,pos;
		cin>>num>>pos;//num �����е�������
		pos++;
		for(int i = 1;i <= num;i++)
		{
			cin>>Q[i].pro;
			Q[i].iswork = false;
		}
		Q[pos].iswork = true;

		int res = 0;
		int tmaxn = 0;//��¼������������ȼ�
		bool print = false;
		st = 1;
		ed = num + 1;

		while(!print)
		{
			tmaxn = 0;
			for(int i = st;i != ed;i = (i % (maxn - 1)) + 1)
				if(tmaxn < Q[i].pro)
					tmaxn = Q[i].pro;

			while(true)
			{
				if(Q[st].pro < tmaxn)
				{
					Q[ed] = Q[st];
					int crap = 0;
					crap++;
					ed = ed % (maxn - 1) + 1;
					st = st % (maxn - 1) + 1;
				}
				else
				{
					if(Q[st].iswork)
						print = true;
					res++;
					st = st % (maxn - 1)+ 1;
					num--;
					break;
				}
			}
		}//print
		cout<<res<<endl;
	}//while casenum
	return 0;
}