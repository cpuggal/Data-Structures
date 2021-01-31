// https://www.geeksforgeeks.org/find-excel-column-name-given-number/
// 

#include<bits/stdc++.h>

#define DEBUG		1
using namespace std;

void printString(int number)
{
	if ((number == 0) || (number < 0))
	{
		cout << "Invalid number" << endl;
		return;
	}
	int rem;
	char temp;
	string str = "";
	
	while(number > 0)
	{
		rem = number % 26;
		
		if(rem == 0)
		{
			str = 'Z' + str;
			number = number / 26 - 1;
			
		}
		else
		{
			temp = rem - 1 + 'A';
			//cout << temp << endl;
			str = temp + str;
			number = number / 26;
		}
		
	}
	cout << str << endl;
}

int main()
{
	printString(26); 
    printString(51); 
    printString(52); 
    printString(80); 
    printString(676); 
    printString(702); 
    printString(705); 
	return 0;
}
