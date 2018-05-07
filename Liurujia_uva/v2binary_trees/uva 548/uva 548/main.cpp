#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;
const int maxn = 10000 + 1000;

int inorder[maxn], postorder[maxn], parent[maxn], temp;
bool isLeaf[maxn];
string str;
int cnt = 0;


bool build_tree(int treeLength, int inStPos, int postStPos, int father)
{
	if (treeLength <= 0)
		return false;

	int nodePos = 0;
	for (int i = inStPos; i < treeLength + inStPos; i++)
	{
		if (postorder[postStPos + treeLength - 1] == inorder[i])
		{
			nodePos = i;
			break;
		}
	}//for
	parent[inorder[nodePos]] = father;

	//×ó×ÓÊ÷
	bool leftson = build_tree(nodePos - inStPos, inStPos, postStPos, inorder[nodePos]);
	
	temp = inorder[nodePos + 1];
	//int rsSt = 0;
	//for (; rsSt < cnt; rsSt++)
	//{
	//	if (postorder[rsSt] == temp)
	//		break;
	//}

	//ÓÒ×ÓÊ÷
	bool rightson = build_tree(treeLength - nodePos - 1 + inStPos, nodePos + 1, postStPos + nodePos - inStPos  , inorder[nodePos]);
	
	isLeaf[inorder[nodePos]] = !(leftson || rightson);
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	std::ios::sync_with_stdio(false);
	while (getline(cin, str))
	{
		stringstream ss(str);
		cnt = 0;
		while (ss >> temp)
			inorder[cnt++] = temp;
		for (int i = 0; i < cnt; i++)
			cin >> postorder[i];
		memset(isLeaf, true, sizeof(isLeaf));
		memset(parent, -1, sizeof(parent));
		build_tree(cnt, 0, 0, -1);

		int res = 0, mini = 0;
		bool flag = true;
		for (int i = 0; i < cnt; i++)
		{
			int val = inorder[i];
			if (!isLeaf[val])
				continue;

			int index = val, summ = 0;
			while (index != -1)
			{
				summ += index;
				index = parent[index];
			}

			if (flag || summ < mini)
			{
				flag = false;
				mini = summ;
				res = val;
			}
		}//for
		cout << res << endl;
		cin.get();
	}
	return 0;
}