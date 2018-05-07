//˼·��ʹ���߶���ʱ��������ʱ����Ҫ�������µ� �����䣬�����Ƚ�Ҫ���µ����ݷ��� ����mark����ϣ�ֻҪ
//ʹ�õ���� �������ʱ���ٽ��������sumֵ���и��£������Ϳ���ʡȥ����ʱ��
//ע�� ����markֵ��Ϊ�㣬˵���������µ�������sumֵû�и���!
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxn = 100000 + 10;

struct node
{
	LL mark, sum;			//������Ϊmark ����markֵΪ��ʱ��˵�����������sumֵ�Ѿ����¹�
}tree[maxn * 3];

int A[maxn];			//�洢��������
int n, m;				//���ָ���n,ѯ����m


void build_tree(int lp,int rp,int i)//������iΪ��������Ϊ[l,,,r]���߶���
{
	if (lp == rp)
	{
		tree[i].sum = A[lp];
		return;
	}

	int mid = (lp + rp) / 2;
	build_tree(lp, mid, i * 2);
	build_tree(mid + 1, rp, i * 2 + 1);
}


void update(int lp, int rp, int i)			//�ñ�Ƿ�ά���߶�������i��Ӧ����Ϊ[lp....rp],Ŀ���Ǹ���[lp,rp]��������� sum
{
	if (tree[i].mark == 0)			//�������i mark==0 ˵���ýڵ����������Ѿ� ���¹���
		return;

	//���� Ҫ���¸������µ����������䣬֮�󽫸ýڵ��mark����´�������������
	int mid = (lp + rp) / 2;
	tree[i * 2].sum += tree[i].mark * (mid - lp + 1);
	tree[i * 2 + 1].sum += tree[i].mark * (rp - mid);

	tree[i * 2].mark += tree[i].mark;
	tree[i * 2 + 1].mark += tree[i].mark;
	tree[i].mark = 0;
}

LL query(int tl, int tr, int lp, int rp, int i)			//�����߶���i ��Ӧ����[lp,,rp] ��������[tl,tr]�ϵ����ֺ�
{
	if (tl > rp || tr < lp)				//����[tl,tr]��[lp,rp]�޽���
		return 0;
	if (tl <= lp && rp <= tr)			//����[tl,tr]��ȫ���� [lp,rp]
		return tree[i].sum;

	update(lp, rp, i);				//������ ����[lp,rp]�� �������sum
	int mid = (lp + rp) / 2;

	return query(tl, tr, lp, mid, i * 2) + query(tl, tr, mid + 1, rp, 2 * i + 1);
}

void add_value(int tl, int tr, int lp, int rp, int i, int val)		//�߶���i[lp,rp] ������[tl,tr] ��ÿ���� + val 
{
	if (tl > rp || tr < lp)
		return;
	if (tl <= lp && rp <= tr) //������[tl,rp] ����[lp,rp] 
	{
		tree[i].sum += val * (rp - lp + 1);
		tree[i].mark += val;
		return;
	}

	//������Ҫ�Ե����� ��tree[i]���и���
	update(lp, rp, i);
	int mid = (lp + rp) / 2;
	add_value(tl, tr, lp, mid, i * 2, val);
	add_value(tl, tr, mid + 1, rp, i * 2 + 1, val);

	tree[i].sum += tree[i * 2].sum + tree[i * 2 + 1].sum;
}


void work()
{
	memset(tree,0, sizeof(tree));
	build_tree(1, n, 1);

	char ch;
	int lp, rp, c;
	for (int i = 0; i < m; i++)
	{
		cin >> ch;
		if ('Q' == ch)
		{
			cin >> lp >> rp;
			LL ans = query(lp, rp, 1, n, 1);
			cout << ans << endl;
		}
		else
		{
			cin >> lp >> rp >> c;
			add_value(lp, rp, 1, n, 1, c);
		}
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	work();
	return 0;
}
