#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;
struct planet
{
	char name[20];
	double population;
	double g;
};

const char* file = "planets.dat";

int main()
{
	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	planet pl;
	if (finout.is_open())
	{
		finout.seekg(0);
		cout << "Here are the contents of the file:" << endl;
		while (finout.read((char*)&pl, sizeof(pl)))
		{
			cout << ct++ << ": " << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		if (finout.eof())
			finout.clear();
		else
		{
			cerr << "Error in reading " << file << ".\n";
			exit(1);
		}
	}
	else
	{
		cerr << "Can't open the file..." << endl;
		exit(1);
	}

	cout << "Enter the record you want to change: ";
	long rec;
	cin >> rec;
	if (rec < 0 || rec >= ct)
	{
		cerr << "Invalid record number ==bye" << endl;
		exit(1);
	}
	streampos place = rec * sizeof(planet);
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "Error on attempted seek" << endl;
		exit(1);
	}
	finout.read((char*)&pl, sizeof(pl));
	cout << rec << ": " << setw(20) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
		finout.clear();

	cout << "Enter the planet name: ";
	cin >> pl.name;
	cout << "Enter the pupolation of the planet: ";
	cin >> pl.population;
	cout << "Enter the gravity of the planet: ";
	cin >> pl.g;
	finout.seekg(place);
	finout.write((char*)&pl, 0).flush();
	if (finout.fail())
	{
		cerr << "Error on attempted write..";
		exit(1);
	}

	ct = 0;
	finout.seekg(0);
	cout << "Here are the contents of the file:" << endl;
	while (finout.read((char*)&pl, sizeof(planet)))
	{
		cout << ct++ << ": " << setw(20) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "Done" << endl;
	system("pause");
	return 0;
}