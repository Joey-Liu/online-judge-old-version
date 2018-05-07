#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>


using namespace std;

bool isPalind, isMirror;
map<char, char> mirrorList;

void init()
{
	mirrorList['A'] = 'A'; mirrorList['E'] = '3';
	mirrorList['H'] = 'H'; mirrorList['I'] = 'I'; mirrorList['J'] = 'L';
	mirrorList['L'] = 'J'; mirrorList['M'] = 'M';
	mirrorList['O'] = 'O'; mirrorList['S'] = '2';
	mirrorList['T'] = 'T';
	mirrorList['U'] = 'U'; mirrorList['V'] = 'V';
	mirrorList['W'] = 'W'; mirrorList['X'] = 'X';
	mirrorList['Y'] = 'Y'; mirrorList['Z'] = '5';
	mirrorList['1'] = '1'; mirrorList['2'] = 'S';
	mirrorList['3'] = 'E'; mirrorList['5'] = 'Z';
	mirrorList['8'] = '8';
}

string str;
bool palind()
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != str[str.length() - 1 - i])
			return false;
	}
	return true;
}

bool mirror()
{
	string mirStr(str);
	for (int i = 0; i < str.length(); i++)
		mirStr[i] = str[str.length() - 1 - i];
	for (int i = 0; i < mirStr.length(); i++)
	{
		if (0 == mirrorList.count(mirStr[i]))
			return false;
		if (mirrorList[mirStr[i]] != str[i])
			return false;
	}

	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	
	while (cin >> str)
	{
		isPalind = palind();
		isMirror = mirror();
			
		if (!isPalind && !isMirror)
			cout << str << " -- is not a palindrome.";
		else if (isPalind && !isMirror)
			cout << str << " -- is a regular palindrome.";
		else if (!isPalind && isMirror)
			cout << str << " -- is a mirrored string." ;
		else if (isPalind && isMirror)
			cout << str << " -- is a mirrored palindrome.";
		cout << endl << endl;
	}
	return 0;
}
