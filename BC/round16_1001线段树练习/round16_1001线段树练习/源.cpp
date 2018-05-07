#include <iostream>
using namespace std;

const int maxn = 256;
int segTree[maxn * 4 + 10];
int arr[maxn];

void buildtree(int node, int begin, int end)//node 目前处理节点在线段树中的位置，begin，end为处理区间
{
	if(begin == end)
		segTree[node] = arr[begin];//
	else
	{
		//递归构造左右子树
		buildtree(2 * node, begin, (begin + end) / 2);
		buildtree(2 * node + 1, (begin + end) / 2 + 1, end);

		if (segTree[2 * node] <= segTree[2 * node + 1])
			segTree[node] = segTree[2 * node];
		else
			segTree[node] = segTree[2 * node + 1];
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 2;
	arr[3] = 4;
	arr[4] = 1;
	arr[5] = 3;

	buildtree(1, 0, 5);
	for (int i = 0; i <= 20; i++)
		cout << "seg" << i << "=" << segTree[i] << endl;
	return 0;

}