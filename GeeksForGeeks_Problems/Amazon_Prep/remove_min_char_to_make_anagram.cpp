// https://www.geeksforgeeks.org/remove-minimum-number-characters-two-strings-become-anagram/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0
#define SIZE	26
int remAnagram(string str1, string str2)
{
	if (str1.length() == 0)
		return str2.length();
	
	if (str2.length() == 0)
		return str1.length();
		
	int count1[SIZE] = {0};
	int count2[SIZE] = {0};	
	
	int i = 0;
	int count = 0;
		
	for(i = 0; i < str1.length(); i++)
		count1[str1[i] - 'a']++;
	
	for(i = 0; i < str2.length(); i++)
		count2[str2[i] - 'a']++;
	
	for(i = 0; i < SIZE; i++)
		count = count + abs(count2[i] - count1[i]);

	return count;
}

int main() 
{ 
    string str1 = "bcadeh", str2 = "hea"; 
    cout << remAnagram(str1, str2) << endl; 
    return 0; 
}
