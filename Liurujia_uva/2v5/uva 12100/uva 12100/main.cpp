#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct Job
{
	int id, priority;
	bool done;
};

queue<Job> que;
vector<Job> job;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum, N, M;
	cin >> kasenum;
	while (kasenum--)
	{
		job.clear();
		while (!que.empty())
			que.pop();

		int tmp;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			Job jo;
			cin >> tmp;
			jo.id = i;
			jo.priority = tmp;
			jo.done = false;
			que.push(jo);
			job.push_back(jo);
		}//for 

		int res = 0;
		while (true)
		{
			Job jo = que.front();
			que.pop();
			bool printable = true;
			int ind = 0;
			for (int i = 0; i < job.size(); i++)
			{
				if (job[i].done)
					continue;
				if (job[i].id == jo.id)
				{
					ind = i;
					continue;
				}
				if (job[i].priority > jo.priority)
				{
					printable = false;
					break;
				}
			}
			if (printable)
			{
				res++;
				job[ind].done = true;
				if (jo.id == M)
					break;
			}
			else
				que.push(jo);
		}//while true
		cout << res << endl;
	}//while kasenum--
	return 0;
}