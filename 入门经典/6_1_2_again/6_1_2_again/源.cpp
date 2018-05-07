#include <iostream>
#include <stack>
using namespace std;

const int num = 1000 + 50;

int main()
{
	int target[num];
	int n;
	while(cin>>n)
	{
		for(int i=1; i <= n;i++)
			cin>>target[i];
		bool ok=true;
		int A=1,B=1;
		stack<int> s;
		while(B <= n)			//B ÎªtargetÖ¸Õë
		{
			if(A==target[B])
			{
				A++;
				B++;
			}
			else if(A < target[B])
			{
				s.push(A++);
			}
			else if(!s.empty() && s.top()==target[B])
			{
				s.pop();
				B++;
			}
			else 
			{
				ok = false;
				break;
			}
		}
		cout<< (true==ok ? "Yes":"No")<<endl;
	}
	system("pause");
	return 0;
}

