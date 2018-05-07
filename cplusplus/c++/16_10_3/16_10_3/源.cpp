#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
const int NUM=6;
const int CHANCE = 6;

using namespace std;

int main()
{
	srand(time(0));
	fstream fin;
	fin.open("word.txt");
	if(false == fin.is_open() )
	{
		cout<<"Can't open the file!\n";
		system("pause");		
		exit(EXIT_FAILURE);
	}
	vector<string> word;
	string temp;
	while(fin>>temp)
		word.push_back(temp);
	cout<<"The size of the text: "<<word.size()<<endl;

	char play;
	cout<<"Will you play a word game? <y/n> :";
	cin>>play; 
	play=tolower(play);

	while('y'==play)
	{
		string target = word[rand() %word.size()];
		int length = target.length();
		string attemp(length,'-');
		string badchars;
		int guesses =CHANCE;
		cout<<"Guess my secret word. It has "<<length
			<<" letters,and you guess\n"
			<<"one letter guess one time.You get "<<guesses
			<<" wrong guesses.\n";
		cout<<"Your word : "<<attemp<<endl;
		while(guesses > 0 && attemp != target)
		{
			char letter;
			cout<<"Guess a letter :";
			cin>>letter;
			if(string::npos != badchars.find(letter) || string::npos != attemp.find(letter))
			{
				cout<<"You have already guessd that,please try some other.\n";
				continue;
			}
			int loc = target.find(letter);
			if(string::npos==loc)
			{
				cout<<"Oh,bad guess!\n";
				guesses--;
				badchars += letter;
			}
			else
			{
				cout<<"Good guess!\n";
				attemp[loc] = letter;
				loc = target.find(letter,loc+1);
				while(string::npos != loc)
				{
					attemp[loc] = letter;
					loc = attemp.find(letter,loc+1);
				}
			}
			cout<<"Your word : "<<attemp<<" ";
			if(attemp != target)
			{
				if(badchars.length() > 0)
					cout<<"Bad choice : "<<badchars<<endl;
				cout<<guesses<<" bad guesses left.\n";
			}
		}
		if(guesses > 0)
			cout<<"That's right!\n";
		else
			cout<<"Sorry,the word is "<<target<<".\n";
		cout<<"Will you play another? <y/n>";
		cin>>play;
		play=tolower(play);
	}

	cout<<"See you\n";
	system("pause");
	return 0;
}





