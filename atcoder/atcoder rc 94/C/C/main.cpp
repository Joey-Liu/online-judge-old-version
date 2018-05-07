#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef int State[3];

const int maxn = 5000 + 50;
int A, B, C;

struct Node
{
	int nu[3];
	int step;
};

bool check(State state) {
	for (int i = 1; i < 3; i++) {
		if (state[i] != state[i - 1])
			return false;
	}
	return true;
}

string convert(int nu[])
{
	string s = "";
	for (int i = 0; i < 3; i++) {
		s += to_string(nu[i]);
	}
	return s;
}

int bfs() {
	Node node;
	node.nu[0] = A; node.nu[1] = B; node.nu[2] = C;
	sort(node.nu, node.nu + 3);
	node.step = 0;
	queue<Node> que;
	set<string> ses;
	que.push(node);
	ses.insert(convert(node.nu));

	int res = -1;
	while (!que.empty()) {
		Node no = que.front();
		que.pop();
		if (check(no.nu)) {
			res = no.step;
			break;
		}


		for (int i = 0; i < 3; i++) {
			Node t = no;
			for (int j = 0; j < 3; j++) {
				if (i == j)
					continue;
				t.nu[j]++;
			}
			sort(t.nu, t.nu + 3);
			string sta = convert(t.nu);
			if (ses.count(sta))
				continue;
			t.step++;
			que.push(t);
			ses.insert(sta);
		}

		for (int i = 0; i < 3; i++) {
			Node t = no;
			t.nu[i] += 2;
			sort(t.nu, t.nu + 3);
			string sta = convert(t.nu);
			if (ses.count(sta))
				continue;
			t.step++;
			que.push(t);
			ses.insert(sta);
		}
	}//while
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> A >> B >> C;
	int res = bfs();
	cout << res << endl;
}