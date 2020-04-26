// https://www.geeksforgeeks.org/count-words-appear-exactly-two-times-array-words/
// Input : { "hate", "love", "peace", "love", 
//                   "peace", "hate", "love", "peace", 
//                   "love", "peace" }; 
// Output : 1
//


#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG		0
#define PRINT_ALL	0

int countWords(string str[], int n)
{
	if (0 == n)
		return 0;

	int i = 0;
	int ans = 0;
	map <string, int> mymap;

	for (i = 0; i < n; i++)
	{
		auto it = mymap.find(str[i]);
		if (it == mymap.end()) // not in map, insert
			mymap.insert({str[i], 1});
		else // already in map, update
			it->second += 1;
	}

	for (auto it = mymap.begin(); it != mymap.end(); it ++)
	{
		if (it->second == 2)
		{
			if(DEBUG)
				cout << it->first << endl;
			ans ++;
		}

		if (PRINT_ALL)
			cout << "Key: " << it->first << ", Count: " << it->second << endl;
	}
	return ans;
}

int main()
{
    string s[] = { "hate", "love", "peace", "love",
                   "peace", "hate", "love", "peace",
                   "love", "peace" };
    int n = sizeof(s) / sizeof(s[0]);
    cout << countWords(s, n) << endl;
    return 0;
}

