#include <iostream>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 50;
bool valid[maxn];
int knw[maxn], N, K;

LL work()
{
	LL pres = 0;
	for (int i = 0; i < K; i++)
	{
		if(!valid[i])
			pres += knw[i];
	}
	LL maxi = pres;
	int ind = 0;

	for (int i = 1; i <= N - K + 1; i++)
	{
		if (!valid[i - 1])
			pres -= knw[i - 1];
		int j = i + K - 1;
		if(!valid[j])
			pres += knw[j];
		
		if (pres > maxi)
		{
			maxi = pres;
			ind = i;
		}
	}
	
	LL res = 0;
	for (int i = 0; i < N; i++)
	{
		if (valid[i])
			res += knw[i];
	}
	for (int i = ind; i <= ind + K - 1; i++)
	{
		if (!valid[i])
			res += knw[i];
	}

	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> knw[i];
	for (int i = 0; i < N; i++)
		cin >> valid[i];
	LL res = work();
	cout << res << endl;
}