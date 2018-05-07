#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct Review
{
	string title;
	int rating;
};
bool FillReview(Review & rr);
void ShowReview(const Review & rr);
bool operator < (const Review & r1,const Review & r2);
bool worseThan(const Review & r1,const Review & r2);


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
		for_each(books.begin(),books.end(),ShowReview);			//注意是函数指针
	/*	cout<<"Reprising:\n"
			<<"Rating\tBook\n";
		vector<Review>::iterator pr;
		for(pr = books.begin();pr != books.end();pr++)
			ShowReview(*pr);
		vector<Review> oldlist(books);
	*/	
		sort(books.begin(),books.end());
		cout<<"Sorted by titles:\nRating\tBook\n";
		for_each(books.begin(),books.end(),ShowReview);

		sort(books.begin(),books.end(),worseThan);
		cout<<"Sorted by ratings:\nRating\tBook\n";
		for_each(books.begin(),books.end(),ShowReview);
	}
	else
		cout<<"Nothing input.";
	cout<<"Bye.\n";
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

bool operator <(const Review & r1,const Review & r2)
{
	if(r1.title < r2.title)
		return true;
	else if(r1.title==r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool worseThan(const Review & r1,const Review & r2)
{
	if(r1.rating < r2.rating)
		return true;
	else 
		return false;
}
