//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int > peo;
//
//int N,pos,val;
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	while (cin >> N)
//	{
//		peo.clear();
//		for (int i = 0; i < N; i++)
//		{
//			cin >> pos >> val;
//			peo.insert(peo.begin() + pos, val);
//		}
//		
//		for (int i = 0; i < peo.size() - 1; i++)
//			cout << peo[i] << " ";
//		cout << peo[peo.size() - 1] << endl;
//	}
//}

//����: �����һ����ӵ��˿�ʼ��ǰ���ǣ�������pi�����߶������� �����пո�λ����Ϣ 
//���߶����� ��logn ʱ�临�Ӷ� �����piӦ�� ����Ŀո�ͬʱҪ�����߶�������Ϣ����ʱpoint[]
//����� ���ؿո��� �߶����е��±꣬�Ӷ������߶����ĸ���
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;

const int maxn = 200000 + 20;

int pos[maxn];
int val[maxn];	//POS val �ֱ�洢��Ŀ��Ҫ���ֵ
int trsize[maxn * 2];	//�洢�߶������� trsize[i] ��ʾ��Ӧ������ ��λ�ø���
int ans[maxn];	//������ ����� ��ans[i] ��ʾ�����е�i���˵����
int peo_num;	//������
int point[maxn]; //point[t] ��ʾ��������� ��t��λ���� trsize�е��±�

void build_tree(int lp,int rp,int i)		//�ӽ��i��������������[lp,rp]��������
{
	trsize[i] = rp - lp + 1;			//���������ж��ٸ��ո�
	if (lp == rp)
	{
		point[lp] = i;					//��¼�ո��� �߶����е�λ��
		return;				
	}

	int mid = (lp + rp) / 2;
	build_tree(lp, mid, 2 * i);
	build_tree(mid + 1, rp, 2 * i + 1);
}


int require(int sum, int lp, int rp, int i)		//�����sum���ո����߶����е�λ�ã�������ֵΪ ��1--n��
{
	if (lp == rp)
		return lp;
	int mid = (lp + rp) / 2;

	if (trsize[2 * i] >= sum)			//���������Ŀո������㹻����ո�Ӧ����������
		return require(sum, lp, mid, i * 2);
	return require(sum - trsize[2 * i], mid + 1, rp, i * 2 + 1);
}

void keep(int i)			//ά���߶���
{
	while (i > 0)
	{
		trsize[i]--;
		i /= 2;
	}
}

void init()
{
	for (int i = 1; i <= peo_num; i++)
		scanf("%d %d", &pos[i], &val[i]);
}

void solve()
{
	memset(trsize, 0, sizeof(trsize));
	memset(ans, 0, sizeof(ans));
	memset(point, 0, sizeof(point));

	build_tree(1, peo_num, 1);
	
	for (int i = peo_num; i >= 1; i--)
	{
		int t = require(pos[i] + 1, 1, peo_num, 1);
		ans[t] = i;	//��t��λ���� �Ǹ��˵����
		//ά���߶���
		keep(point[t]);
	}

	for (int i = 1; i <= peo_num - 1; i++)
		printf("%d ", val[ans[i] ]);
	printf("%d\n", val[ans[peo_num]]);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &peo_num))
	{
		init();
		solve();
	}
	return 0;
}
