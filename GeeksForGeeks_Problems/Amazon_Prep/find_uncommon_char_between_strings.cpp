// https://www.geeksforgeeks.org/find-uncommon-characters-two-strings/
// Input :  characters , alphabets 
// Output : b c l p r
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

void findAndPrintUncommonChars(string str1, string str2)
{
	if ((str1.length() == 0) && (str2.length() == 0))
		return;
	
	map<char, int> mymap;
	int i,j;
	
	for(i = 0; i < str1.length(); i++)
	{
		auto it = mymap.find(str1[i]);

		if (it == mymap.end()) // insert only once
			mymap.insert({str1[i], 1});
	}
	
	for(i = 0; i < str2.length(); i++)
	{
		auto it = mymap.find(str2[i]);
		if (it == mymap.end()) // insert only once
			mymap.insert({str2[i], 2});
		else
			it->second = -1;
	}
	for (auto it = mymap.begin(); it != mymap.end(); it++)
	{
		if (it->second != -1) // Char is either in str1 or str2, then print
			cout << it->first << " ";
	}
	cout << endl;
}

int main() 
{ 
    string str1 = "characters"; 
    string str2 = "alphabets"; 
    findAndPrintUncommonChars(str1, str2); 
    findAndPrintUncommonChars("geeksforgeeks", "geeksquiz"); 
    return 0; 
} 
  
