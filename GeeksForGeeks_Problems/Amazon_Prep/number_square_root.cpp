// https://www.geeksforgeeks.org/square-root-of-an-integer/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int floorSqrt(int num)
{
	if ((0 == num) || (1 == num))
		return num;
	
	int i = 1;
	
	while(i*i < num)
	{
		i++;
	}
	return i - 1; // floor required.
}

int main() 
{ 
    int x = 11; 
    cout << floorSqrt(x) << endl; 
    return 0; 
} 
