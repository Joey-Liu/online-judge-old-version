#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Review
{
	string title;
	int rating;
};
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
	vector<Review> books;
	Review temp;
	while(FillReview(temp))
		books.push_back(temp);
	int num = books.size();
	if(num > 0)
	{
		cout<<"You entered the following:\n"
			<<"Rating\tBooks\n";
		for(int i=0;i<num;i++)
			ShowReview(books[i]);
		cout<<"Reprising:\n"
			<<"Rating\tBook\n";
		vector<Review>::iterator pr;
		for(pr = books.begin();pr != books.end();pr++)
			ShowReview(*pr);
		vector<Review> oldlist(books);
		if(num > 3)
		{
			books.erase(books.begin()+1,books.begin()+3);
			cout<<"After ereasure:\n";
			for(pr = books.begin();pr != books.end();pr++)
				ShowReview(*pr);
			//插入一个结点
			books.insert(books.begin(),oldlist.begin()+1,oldlist.begin()+2);
			cout<<"After inserting:\n";
			for(pr = books.begin();pr != books.end();pr++)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout<<"Swapping oldlist with books:\n";
		for(pr = books.begin();pr != books.end();pr++)
			ShowReview(*pr);
	}
	else 
		cout<<"Nothing entered,nothing gained.\n";
	system("pause");
	return 0;
}

bool FillReview(Review & rr)
{
	cout<<"Enter book title (quit to quit): ";
	getline(cin,rr.title);
	if("quit"==rr.title)
		return false;
	cout<<"Enter the book rating: ";
	if(!(cin>>rr.rating))
		return false;
	while('\n' != cin.get())
		continue;
	return true;
}

void ShowReview(const Review & rr)
{
	cout<<rr.rating<<"\t"<<rr.title<<endl;
}



