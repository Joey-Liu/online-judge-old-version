#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


string mores[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

string get_mores(const string & word)
{
	string smorse = "";
	for (int i = 0; i < word.size(); i++)
		smorse += mores[word[i] - 'a'];
	return smorse;
}

class Solution 
{
public:
	int uniqueMorseRepresentations(vector<string>& words) 
	{
		set<string> sstr;
		for (int i = 0; i < words.size(); i++)
			sstr.insert(get_mores(words[i]));
		return sstr.size();
	}
};