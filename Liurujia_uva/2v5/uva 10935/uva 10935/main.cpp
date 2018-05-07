#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N && N)
	{
		queue<int> cards;
		for (int i = 1; i <= N; i++)
			cards.push(i);

		cout << "Discarded cards:";
		bool first = true;
		while (cards.size() > 1)
		{
			if (!first)
				cout << ",";
			first = false;
			int x = cards.front();
			cout <<" "<< x;
			cards.pop();
			x = cards.front();
			cards.pop();
			cards.push(x);
		}
		cout << endl;
		cout << "Remaining card: " << cards.front() << endl;
	}
	return 0;
}