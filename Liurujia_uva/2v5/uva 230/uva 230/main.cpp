#include <iostream>
#include <stdio.h>

#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Book
{
	string author;
	string title;
	bool borrowed, returned;
	Book()
	{
		borrowed = false;
		returned = false;
	}
};

bool cmp(const Book & b1, const Book & b2)
{
	if (b1.author != b2.author)
		return b1.author < b2.author;
	return b1.title < b2.title;
}

vector<Book> books;

void borrow_book(string title)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].title == title)
		{
			books[i].borrowed = true;
			break;
		}
	}
}

void return_book(string title)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].title == title)
		{
			books[i].returned = true;
			break;
		}
	}
}

void shelf()
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].borrowed && books[i].returned)
		{
			int j;
			for (j = i; j >= 0; j--)
			{
				if (!books[j].borrowed && !books[j].returned)
					break;
			}
			if (-1 == j)
				cout << "Put \"" << books[i].title << "\" first" << endl;
			else
			{
				cout << "Put \"" << books[i].title << "\" after \"" << books[j].title <<"\""<< endl;
			}
			books[i].borrowed = books[i].returned = false;
		}//if
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string str;
	while (getline(cin, str) && "END" != str)
	{
		int pos = str.find_last_of("\"");
		string title = str.substr(1, pos - 1);
		string author = str.substr(pos + 5);
		Book b;
		b.author = author;
		b.title = title;
		books.push_back(b);
	}
	
	sort(books.begin(), books.end(), cmp);
	while (cin >> str && "END" != str)
	{
		string ti, title;
		if ("BORROW" == str)
		{
			cin.get();
			getline(cin, ti);
			title = ti.substr(1, ti.size() - 2);
			borrow_book(title);
		}
		else if ("RETURN" == str)
		{
			cin.get();
			getline(cin, ti);
			title = ti.substr(1, ti.size() - 2);
			return_book(title);
		}
		else
		{
			shelf();
			cout << "END" << endl;
		}
	}//while
	return 0;
}



