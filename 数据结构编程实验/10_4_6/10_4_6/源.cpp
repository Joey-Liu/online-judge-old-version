#include <iostream>
using namespace std;
const int maxn = 100 + 50;

struct no
{
	int key;
	int lp;
	int rp;
	int rang;//�ӽڵ������
}node[maxn];

void init(int num)
{
	cin>>node[0].key;
	node[0].lp = -1;
	node[0].rp = -1;
	node[0].rang = 1;

	for(int i = 1;i < num;i++)
	{
		cin>>node[i].key;
		node[i].lp = node[i].rp = -1;
		node[i].rang = 1;
		int pos = 0;
		while(true)
		{
			if(node[i].key > node[pos].key)
			{
				node[pos].rang++;//�������ģ��ܻ�ʹ�� �����ڵ���������
				if(-1==node[pos].rp)
				{
					node[pos].rp = i;
					break;
				}
				else
					pos = node[pos].rp;
			}
			else
			{
				node[pos].rang++;
				if(-1==node[pos].lp)
				{
					node[pos].lp = i;
					break;
				}
				else
					pos = node[pos].lp;
			}
		}//while true
	}
}

int compute(int t)//node ����
{
	if(t < 0)
		return 1;
	if(1==node[t].rang)//���ֻ��һ���ڵ㣬���߲�����
		return 1;
	else
	{
		int res = compute(node[t].lp) * compute(node[t].rp);
		int t1 = 1,t2 = 1;

		//�����������
		if(node[t].lp >= 0)
		{
			for(int i = 0;i < node[node[t].lp].rang;i++)
				t1 = (t1 * (node[t].rang - 1 - i)) % 9901;
		
			for(int i = 1;i <= node[node[t].lp].rang;i++)
				t2 = (t2 * i) % 9901;
			t1 = t1 / t2;
		}
		
		res = (res * t1) % 9901;
		return res;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(cin>>n && n != 0)
	{
		init(n);
		cout<<compute(0)<<endl;
	}
	return 0;
}