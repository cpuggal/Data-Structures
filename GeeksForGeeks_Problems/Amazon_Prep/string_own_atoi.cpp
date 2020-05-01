// https://www.geeksforgeeks.org/write-your-own-atoi/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int myAtoi(string str)
{
	if (str.length() == 0)
		return 0;
	
	int num = 0, i;
	int temp;
	bool negative = false;
	
	for(i = 0; i < str.length(); i++)
	{
		if(str[i] == '-')
		{
			negative = true;
			i++;
		}
		if(DEBUG)
		{
			temp = str[i] - '0';
			cout << temp << " ";
		}
		num = num * 10 + (str[i] - '0');
	}
	if(negative)
		return ((num) * (-1));
	else
		return num;
}

int main() 
{ 
    char str[] = "89789"; 
    int val = myAtoi(str); 
    printf("%d\n", val); 
    char str1[] = "-123"; 
    cout << myAtoi(str1) << endl; 
    return 0; 
} 
