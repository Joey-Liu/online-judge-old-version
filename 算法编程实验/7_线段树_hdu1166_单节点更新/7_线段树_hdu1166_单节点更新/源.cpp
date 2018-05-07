#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 50000 + 10;
int tree[maxn * 4];			//�߶���,����Ҷ�ڵ��⣬����Ϊ����Ӧ����������
int casenum;
int N;			//N���������
int peo[maxn];		//�����������
char str[30];

void build_tree(int node,int lp,int rp)		//���node ����Ӧ����[lp,rp]
{
	if (lp == rp)
		tree[node] = peo[lp];
	else
	{
		int mid = (lp + rp) >> 1;
		build_tree(node << 1, lp, mid);
		build_tree((node << 1) + 1, mid + 1, rp);

		tree[node] = tree[node << 1] + tree[(node << 1) + 1];
	}
}


//���� node ����[lp,rp]����army val��
void add_peo(int node, int lp, int rp,int army,int val)
{
	//army ������[lp,rp]֮��
	if (army < lp || army > rp)
		return;
	else if (lp == rp && lp == army)
	{
		tree[node] += val;
		return;
	}

	tree[node] += val;
	int mid = (lp + rp) >> 1;
	add_peo(node << 1, lp, mid, army, val);
	add_peo((node << 1) + 1, mid + 1, rp, army, val);
}
//
//void sub_peo(int node, int lp, int rp, int army, int val)
//{
//	if (army < lp || army > rp)
//		return;
//	else if (lp == rp && lp == army)
//	{
//		tree[node] -= val;
//		return;
//	}
//
//	tree[node] -= val;
//	int mid = (lp + rp) / 2;
//	sub_peo(node * 2, lp, mid, army, val);
//	sub_peo(node * 2 + 1, mid + 1, rp, army, val);
//}

int query(int node, int tl, int tr, int lp, int rp)
{
	//��� ��lp��rp�� ������[tl,tr]���κν���
	if (tr < lp || tl > rp)
		return 0;
	//��� [lp,rp]������ [tl,tr]��Χ��
	if (tl <= lp && rp <= tr)
		return tree[node];

	int mid = (lp + rp) >> 1;
	return query(node << 1, tl, tr, lp, mid) +
		query((node <<1) + 1, tl, tr, mid + 1, rp);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int m, n,index = 1;			//ָ����������
	//cin >> casenum;
	scanf("%d", &casenum);
	while (casenum--)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			//cin >> peo[i];
			scanf("%d",&peo[i]);
		}
		//cout << "Case " << index++ << ":" << endl;
		printf("Case %d:\n", index++);
		build_tree(1, 1, N);
		//cin >> str;
		scanf("%s", str);
		while ('E' != str[0])
		{
			scanf("%d %d", &m, &n);
			if ('Q' == str[0])
			{
				printf("%d\n", query(1, m, n, 1, N));
			}
			else if ('A' == str[0])
				add_peo(1, 1, N, m, n);
			else
				add_peo(1, 1, N, m, -n);
			scanf("%s", str);
		}//while end
	}//while casenum

	return 0;
}
