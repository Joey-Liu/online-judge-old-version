#include<iostream>
#include<stdio.h>
//#pragma warning(disable:4996)
using namespace std;

int dads[100010];

int relation[100010];

//int getdad(int i) {
//	int k = i;
//	int temp = relation[i];
//	while (dads[k] != k) {
//		k = dads[k];
//		temp = temp * relation[k];
//	}
//	if (i != k) {
//		dads[i] = k;
//		relation[i] = temp;
//	}
//	return k;
//}

int getdad(int i) 
{
	if (i == dads[i])
		return i;
	int tmp = dads[i];
	dads[i] = getdad(dads[i]);
	if (dads[i] != tmp)
		relation[i] = relation[tmp] * relation[i];
	return dads[i];
}

void update(int i, int j) {
	int dad_i = getdad(i);
	int dad_j = getdad(j);
	dads[dad_i] = dad_j;
	//relation[dad_i] = relation[i] * relation[i] * (-1);
	relation[dad_i] = relation[i] * relation[j] * (-1);
	
}

int check(int i, int j) {
	if (getdad(i) != getdad(j)) return 0;
	if (relation[i] == relation[j]) return 1;
	if (relation[i] != relation[j]) return -1;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, n, m, a, b;
	scanf("%d", &t);
	char str[3];
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			dads[i] = i;
			relation[i] = 1;
		}
		
		while (m--)
		{
			scanf("%s%d%d", str, &a, &b);
			a -= 1;
			b -= 1;
			if (str[0] == 'D')
			{
				update(a, b);
			}
			else
			{
				int result = check(a, b);
				if (result == -1)  printf("In different gangs.\n");
				else if (result == 1) printf("In the same gang.\n");
				else if (result == 0) printf("Not sure yet.\n");
			}
		}
	}
	return 0;
}