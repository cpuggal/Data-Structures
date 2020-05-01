// https://www.geeksforgeeks.org/reverse-an-array-upto-a-given-position/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

void printRLE(string str)
{
	if(str.length() == 0)
		return;
		
	int i = 0, count = 1;
	char ch = str[0];
	for(i = 1; i < str.length(); i++)
	{
		if (ch == str[i])
			count++;
		else
		{
			cout << ch << count;
			ch = str[i];
			count = 1;
		}
	}
	cout << ch << count << endl;
}

int main() 
{ 
    string str = "wwwwaaadexxxxxxywww"; 
    printRLE(str); 
    return 0; 
}
