#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
const char* file = "guest.txt";

int main()
{
	char ch;

	ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		cout << "Here are the contents of the " << file << " file:\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}

	ofstream fout(file,ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "Can't open the file for output,bye!"<<endl;
		exit(1);
	}
	
	cout << "Enter the new guest name(blank line to quit):" << endl;
	string name;
	while (getline(cin, name) && name.size() > 0)
		fout << name << endl;
	fout.close();

	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		cout << "The current contents of the file is:" << endl;
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}
	cout << "\nDone.\n";
	system("pause");
	return 0;
}