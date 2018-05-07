#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string filename;

	cout << "Please enter the file name: ";
	cin >> filename;

	ofstream fout(filename.c_str());

	fout << "For the user's eyes only!" << endl;
	cout << "Enter your secret number: ";
	double secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();

	ifstream fin(filename.c_str());
	cout << "The file content is here:" << endl;
	char ch;
	while (fin.get(ch))
		cout << ch;

	cout << "Bye!" << endl;
	system("pause");
	return 0;
}