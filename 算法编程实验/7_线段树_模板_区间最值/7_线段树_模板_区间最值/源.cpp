#include <iostream>

using namespace std;

const int maxn = 100;
int tree[maxn * 4];			//�߶�������,�������Ԫ�����⣬�����������ʾ����������СԪ�� ���
int num[] = { 3, 4, 5, 7, 2, 1, 0, 3, 4, 5 };

void build_tree(int node, int lp, int rp)
{
	if (lp == rp)
		tree[node] = lp;	//ֻ��һ��Ԫ�أ�tree[node]����ýڵ����
	else
	{
		int mid = (lp + rp) / 2;
		build_tree(node * 2, lp, mid);
		build_tree(node * 2 + 1, mid + 1, rp);

		if (num[tree[node * 2]] < num[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2 + 1];
	}
}

// ��ǰ����node ��Ӧ��Χ[lp,rp]
int query(int node, int tl, int tr, int lp, int rp)		//�ҳ�����[tl,tr]����СԪ�� ���
{
	//����[tl,tr] �뵱ǰ��ѯ����[lp,rp]û���κν���
	if (tl > rp || tr < lp)
		return -1;


	//����[lp,rp]������[tl,tr]�ڲ�
	if (tl <= lp && rp <= tr)
		return tree[node];

	int mid = (lp + rp) / 2;
	int p1 = query(2 * node, tl, tr, lp, mid);
	int p2 = query(2 * node + 1, tl, tr, mid + 1, rp);

	if (p1 == -1)
		return p2;
	if (p2 == -1)
		return p1;
	if (num[p1] < num[p2])
		return p1;
	return p2;
}

int main()
{
	memset(tree, 0, sizeof(tree));
	build_tree(1, 0, sizeof(num) / sizeof(num[0]) - 1);
	cout << num[query(1, 1, 3, 1, sizeof(num) / sizeof(num[0]) ) ]<<endl;
	cout << num[query(1, 5, 8, 1, sizeof(num) / sizeof(num[0]) ) ]<<endl;
	cout << num[query(1, 3, 5, 1, sizeof(num) / sizeof(num[0]))] << endl;
	system("pause");
	return 0;

}