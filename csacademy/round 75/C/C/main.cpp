#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <string.h>
using namespace std;
const int maxn = 100000 + 50;
int N;
double X, Y;
struct Node {
	double ti;
	int id;
};
Node normal[maxn], decre[maxn], incre[maxn];
Node bk_normal[maxn], bk_decre[maxn], bk_incre[maxn];

bool cmp(const Node a, const Node b) {
	if (a.ti != b.ti)
		return a.ti < b.ti;
	return a.id < b.id;
}

int work(int ind)
{
	int n1 = lower_bound(normal, normal + N, bk_incre[ind], cmp) - normal;
	int n2 = lower_bound(decre, decre + N, bk_normal[ind], cmp) - decre;
	return min(n1, n2) + 1;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> X >> Y;
	for (int i = 0; i < N; i++)
	{
		double di, v;
		cin >> di >> v;
		normal[i].id = i;
		normal[i].ti = di / v;
		decre[i].id = i;
		decre[i].ti = di / (v - Y);
		incre[i].id = i;
		incre[i].ti = di / (v + X);
	}
	memcpy(bk_normal, normal, sizeof(normal));
	memcpy(bk_incre, incre, sizeof(incre));
	memcpy(bk_decre, decre, sizeof(decre));

	sort(normal, normal + N, cmp);
	sort(decre, decre + N, cmp);
	sort(incre, incre + N, cmp);
	for (int i = 0; i < N; i++) {
		int r = work(i);
		cout << r << endl;
	}
	return 0;
}