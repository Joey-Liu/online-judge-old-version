#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		q.push(i+1);
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
		if(!q.empty())
		{
			q.push(q.front());
			q.pop();
		}

	}
	system("pause");
	return 0;
}



