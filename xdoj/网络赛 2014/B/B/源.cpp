#include <iostream>
using namespace std;

const int maxn = 100 + 20;
struct node
{
	int first;
	int second;
};
int sum_of_digit(int n)
{
	if(n < 10)
		return n;
	else
		return (n % 10) + sum_of_digit(n / 10);
}

int main()
{
	node record[maxn];
	int size;
	cin>>size;

	for(int i =0;i < size;i++)
		cin>>record[i].first;

	for(int i = 0;i < size;i++)
		record[i].second = sum_of_digit(record[i].first);

	for(int i = 0;i < size;i++)
	{
		for(int j =0;j < size - i -1;j++)
		{
			if(record[j].first > record[j + 1].first)
			{
				node temp = record[j];
				record[j] = record[j + 1];
				record[j + 1] = temp;
			}
		}
	}

	for(int i = 0;i < size;i++)
	{
		for(int j =0;j < size - i -1;j++)
		{
			if(record[j].second > record[j + 1].second)
			{
				node temp = record[j];
				record[j] = record[j + 1];
				record[j + 1] = temp;
			}
		}
	}

	for(int i =0;i < size;i++)
		cout<<record[i].first<<endl;
	system("pause");
	return 0;
}