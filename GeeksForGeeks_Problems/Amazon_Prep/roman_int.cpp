// https://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/
//
// Input : 3549
// Output : MMMDXLIX
//


#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

void printRoman(int number)
{
	int integers[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int idx = 12;   
	int i, j;
	while(number > 0)
	{
		i = number / integers[idx];
		number = number % integers[idx];
		while(i)
		{
			cout << sym[idx];
			i --;
		}
		idx --;
	}
	cout << endl;
}

int main() 
{ 
    int number = 3549;
    printRoman(number); 
  
    return 0; 
}
