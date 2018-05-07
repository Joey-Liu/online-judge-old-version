#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int num;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>num && num != 0)
	{
		int tmp,res = 0;
		priority_queue <int,vector<int>,greater<int> > q;

		for(int i = 0;i < num;i++)
		{
			cin>>tmp;
			q.push(tmp);
		}

		while(q.size() != 1)
		{
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			
			res += a + b;
			q.push(a + b);
		}
		
		//res += q.top();
		cout<<res<<endl;	
	}
	return 0;
}