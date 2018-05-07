#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

inline void eatline()
{
	while (cin.get() != '\n')
		continue;
}

struct plant
{
	char name[20];
	double population;
	double g;
};

const char* file = "planets.dat";

int main()
{
	plant pl;
	cout << fixed << right;

	ifstream fin;
	fin.open(file, ios_base::binary | ios_base::in);
	if (fin.is_open())
	{
		cout << "Here are the content of the file:" << endl;
		while (fin.read((char*)&pl, sizeof(plant)) )
		{
			cout.width(20);
			cout <<setw(20)<< pl.name << ":"
				<< setprecision(0) << setw(20) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}

	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "Can't open the file" << endl;
		exit(0);
	}

	cout << "Enter planet name(blank line to quit): ";
	cin.getline(pl.name, 20);
	while (pl.name[0] != '\0')
	{
		cout << "Enter the planetary population: ";
		cin >> pl.population;
		cout << "Enter the acceleration of gravity: ";
		cin >> pl.g;
		fout.write((char*)&pl, sizeof(plant));
		cout << "Enter planet name(blank line to quit): ";
		cin.getline(pl.name,20);
	}
	fout.close();

	fin.clear();
	fin.open(file, ios_base::binary | ios_base::in);
	if (fin.is_open())
	{
		cout << "Here are the content of the file:" << endl;
		while (fin.read((char*)&pl, sizeof(plant)))
		{
			cout << setw(20)<<pl.name << ":"
				<< setprecision(0) << setw(20) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}
	cout << "Bye!" << endl;
	system("pause");
	return 0;
}