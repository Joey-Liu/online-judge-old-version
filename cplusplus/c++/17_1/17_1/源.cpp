#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	const char* str1 = "Florida";
	const char* str2 = "Kansas";
	const char* str3 = "Euphoria";

	int len = strlen(str2);
	cout << "First"<<endl;
	int i = 0;
	for (i = 1; i <= len; i++)
		cout.write(str2, i);

	cout << endl << "Second" << endl;
	for (i = len; i > 0; i--)
		cout.write(str2, i);

	cout << "Exceeding" << endl;
	cout.write(str2, len + 5);
	cout << endl;

	long val = 1234587854;
	cout.write((char*)&val, sizeof(long)) << endl;
	system("pause");
	return 0;
}