// https://www.geeksforgeeks.org/count-numbers-first-last-digits/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	

using namespace std;

int getCountWithSameStartAndEnd_int(int num)
{
	if(num < 10)
		return num;
		
	int sum = 10; // consider 0 to 9 as 10numbers atleast
	
	int tens = num/10;
	int last_digit = num % 10;
	int first_digit;
	
	while(num != 0)
	{
		first_digit = num % 10;
		num = num/10;
	}
	int temp = 0; 
	
	if(first_digit > last_digit) // 807 and 809 will have a diff of 1 i.e 808
		temp = -1;
		
	return tens + sum + temp;
}


int getCountWithSameStartAndEnd(int start, int end)
{
	int s = getCountWithSameStartAndEnd_int(start);
	int e = getCountWithSameStartAndEnd_int(end);
	return e - s;
}

int main() 
{ 
    int start = 5, end = 40; 
  
    cout << getCountWithSameStartAndEnd(start, end) << endl; 
  
    return 0; 
} 

