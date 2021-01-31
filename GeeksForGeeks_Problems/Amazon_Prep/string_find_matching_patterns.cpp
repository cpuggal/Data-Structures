// https://www.geeksforgeeks.org/find-all-strings-that-match-specific-pattern-in-a-dictionary/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0
using namespace std;

string encode_string(string str)
{
	map<char, int>mymap;
	int i = 0;
	int len = str.length();
	int val = 1;
	string res = "";
	for(i = 0; i < len; i++)
	{
		if(mymap.find(str[i]) == mymap.end())
		{
			mymap[str[i]] = val;
			val++;
		}
		res = res + to_string(mymap[str[i]]);
	}
	return res;
}

// Uses each string position as integer for making a hash value

void findMatchedWords1(unordered_set<string> dict, string pattern)
{
	string pattern_hash = encode_string(pattern);
	int pattern_len = pattern.length();
	string curr_string = "";
	int curr_string_len;
	for (auto it = dict.begin(); it != dict.end(); it++)
	{
		curr_string = *it;
		curr_string_len = curr_string.length();
		if ((curr_string_len == pattern_len) && (encode_string(curr_string) == pattern_hash))
			cout << curr_string << " ";
	}
	cout << endl;
}

bool check_matching(string word, string pattern)
{
	if(word.length() != pattern.length())
		return false;
	
	map<char, char> mymap;
	int len = pattern.length();
	int i = 0;
	
	for(i = 0; i < len; i++)
	{
		auto it = mymap.find(pattern[i]);
		if (it == mymap.end())
		{
			mymap[pattern[i]] = word[i];
		}
		else // pattern char is already in map
		{
			if (word[i] == it->second) //pattern char matches word char from map
				continue;
			else
				return false;
		}
	}
	return true;
}

void findMatchedWords2(unordered_set<string> dict, string pattern)
{
	for(string word: dict)
	{
		if(check_matching(word, pattern))
			cout << word << " ";
	}
	cout << endl;
}

int main() 
{ 
    unordered_set<string> dict = { "abb", "abc", 
                                   "xyz", "xyy" }; 
    string pattern = "foo"; 
  
    findMatchedWords1(dict, pattern); 
    findMatchedWords2(dict, pattern); 
  
	findMatchedWords1({"xxyzzaa"}, "mmnoopp"); 
    findMatchedWords2({"xxyzzaa"}, "mmnoopp"); 
    return 0; 
} 

