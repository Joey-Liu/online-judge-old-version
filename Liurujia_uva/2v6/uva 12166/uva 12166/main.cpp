#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	long long weight;
	int depth;
	Node* lp, *rp;
	Node()
	{
		lp = NULL;
		rp = NULL;
	}
};

string str;
map<long long, int> tab;
vector<Node* > vn;

Node* build_tree(int & index, int depth)
{
	if (isdigit(str[index]))
	{
		int res = 0;
		while (isdigit(str[index]))
		{
			res = res * 10 + str[index] - '0';
			index++;
		}
		Node *p = new Node();
		p->depth = depth;
		p->weight = res;
		vn.push_back(p);
		return p;
	}

	Node *p = new Node();
	if ('[' == str[index])
	{
		index++;
		p->lp = build_tree(index, depth + 1);
		while (',' == str[index] || ']' == str[index])
			index++;
		p->rp = build_tree(index, depth + 1);
		p->weight = p->lp->weight + p->rp->weight;
		p->depth = depth;
		return p;
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	cin >> kasenum;
	cin.get();
	while (kasenum--)
	{
		tab.clear();
		vn.clear();
		getline(cin, str);
		int index = 0;
		Node *root = build_tree(index, 0);
		
		int ma = -1;
		for (int i = 0; i < vn.size(); i++)
		{
			Node *p = vn[i];
			long long eq_sum = p->weight * (1 << p->depth);
			tab[eq_sum]++;
			ma = max(ma, tab[eq_sum]);
		}
		cout << vn.size() - ma << endl;
	}
	return 0;
}