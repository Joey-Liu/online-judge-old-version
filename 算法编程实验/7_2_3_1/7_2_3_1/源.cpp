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
typedef __int64 LL;

const __int64 maxn = 100000 + 10;

struct node
{
	LL mark, sum;			//������Ϊmark ����markֵΪ��ʱ��˵�����������sumֵ�Ѿ����¹�
}tree[maxn * 3];

__int64 A[maxn];			//�洢��������
int n, m;				//���ָ���n,ѯ����m


void build_tree(__int64 lp,__int64 rp,__int64 i)//������iΪ��������Ϊ[l,,,r]���߶���
{
	if (lp == rp)
	{
		tree[i].sum = A[lp];
		return;
	}

	__int64 mid = (lp + rp) / 2;
	build_tree(lp, mid, i * 2);
	build_tree(mid + 1, rp, i * 2 + 1);
	tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
}


void update(__int64 lp, __int64 rp, __int64 i)			//�ñ�Ƿ�ά���߶�������i��Ӧ����Ϊ[lp....rp],Ŀ���Ǹ���[lp,rp]��������� sum
{
	if (tree[i].mark == 0)			//�������i mark==0 ˵���ýڵ����������Ѿ� ���¹���
		return;

	//���� Ҫ���¸������µ����������䣬֮�󽫸ýڵ��mark����´�������������
	__int64 mid = (lp + rp) / 2;
	tree[i * 2].sum += tree[i].mark * (mid - lp + 1);
	tree[i * 2 + 1].sum += tree[i].mark * (rp - mid);

	tree[i * 2].mark += tree[i].mark;
	tree[i * 2 + 1].mark += tree[i].mark;
	tree[i].mark = 0;
}

LL query(__int64 tl, __int64 tr, __int64 lp, __int64 rp, __int64 i)			//�����߶���i ��Ӧ����[lp,,rp] ��������[tl,tr]�ϵ����ֺ�
{
	if (tl > rp || tr < lp)				//����[tl,tr]��[lp,rp]�޽���
		return 0;
	if (tl <= lp && rp <= tr)			//����[tl,tr]��ȫ���� [lp,rp]
		return tree[i].sum;

	update(lp, rp, i);				//������ ����[lp,rp]�� �������sum
	__int64 mid = (lp + rp) / 2;

	return query(tl, tr, lp, mid, i * 2) + query(tl, tr, mid + 1, rp, 2 * i + 1);
}

void add_value(__int64 tl, __int64 tr, __int64 lp, __int64 rp, __int64 i, __int64 val)		//�߶���i[lp,rp] ������[tl,tr] ��ÿ���� + val 
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
	__int64 mid = (lp + rp) / 2;
	add_value(tl, tr, lp, mid, i * 2, val);
	add_value(tl, tr, mid + 1, rp, i * 2 + 1, val);

	tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
}


void work()
{
	memset(tree,0, sizeof(tree));
	build_tree(1, n, 1);

	char ch;
	__int64 lp, rp, c;
	for (__int64 i = 0; i < m; i++)
	{
		getchar();
		scanf("%c", &ch);
		if ('Q' == ch)
		{
			scanf("%I64d %I64d", &lp, &rp);
			__int64 ans = query(lp, rp, 1, n, 1);
			//cout << ans << endl;
			printf("%I64d\n", ans);
		}
		else
		{
			//cin >> lp >> rp >> c;
			scanf("%I64d %I64d %I64d", &lp, &rp, &c);
			add_value(lp, rp, 1, n, 1, c);
		}
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	//for (__int64 i = 1; i <= n; i++)
	//	cin >> A[i];
	for (__int64 i = 1; i <= n; i++)
		scanf("%I64d", &A[i]);
	//getchar();
	work();
	return 0;
}
