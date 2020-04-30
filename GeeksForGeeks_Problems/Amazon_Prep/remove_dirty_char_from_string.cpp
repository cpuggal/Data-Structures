// https://www.geeksforgeeks.org/remove-characters-from-the-first-string-which-are-present-in-the-second-string/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0


char *removeDirtyChars(char *str, char *mask)
{
	if (mask == NULL)
		return str;
	
	bool counter[256] = {false};
	int i = 0;
	char ch;
	
	while(mask[i] != '\0')
	{
		ch = mask[i];
		counter[int(ch)] = true;
		i++;
	}
	int str_ptr = 0;
	int new_str_ptr = 0;
	
	while(*(str+str_ptr) != '\0')
	{
		ch = str[str_ptr];
		
		if (counter[int(ch)] == false)
		{
			*(str + new_str_ptr) = *(str + str_ptr);
			new_str_ptr++;
		}
		str_ptr ++;
	}
	*(str+new_str_ptr) = '\0';
	return str;
}

string removeDirtyChars_string(string str, string mask)
{
	if (0 == mask.length())
		return str;
	
	map<char, int> counter;
	int i = 0, j;
	char ch;
	int len_mask = mask.length();
	int len_str = str.length();
	
	while(i != len_mask)
	{
		auto it = counter.find(mask[i]);
		if (it == counter.end())
			counter.insert({mask[i], 1});
		
		i++;
	}
	
	i = 0;
	while(i != len_str)
	{
		ch = str[i];
		auto it = counter.find(ch);
		
		if (it != counter.end()) // char is there in mask so remove from string
			str.erase(str.begin() + i);
		else
			i++;
	}
	
	return str;
}

int main() 
{ 
    char str[]         = "geeksforgeeks"; 
    char mask_str[]  = "mask"; 
    printf("%s\n", removeDirtyChars(str, mask_str)); 
    cout << removeDirtyChars_string("geeksforgeeks", "mask") << endl;
    return 0; 
} 
