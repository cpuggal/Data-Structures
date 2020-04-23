//  https://www.geeksforgeeks.org/check-bits-number-set/
//
//  Input : 7 
//  Output : Yes
//  Input : 8
//  Output : No
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string areAllBitsSet_while(int n)
{
	string def = "No";
	
	if (n == 0)
		return def;
	int i = 1;
	
	while(n != 0)
	{
		if (n & 1)
		{
			n = n >> 1;
		}
		else
			return def;
	}
	return "Yes";
}

string areAllBitsSet_log(int n)
{
	string def = "No";

	if (n == 0)
		return def;
	
	double num = log2(n + 1);
	int temp = num;

//	cout << temp << " " << num << endl;

	if (temp == num) // or if (int(num) == num)
		return "Yes";
	else
		return def;
}

string areAllBitsSet_And(int n)
{
	string def = "No";
	
	if (n == 0)
		return def;
	
	if ((n & (n + 1)) == 0)
		return "Yes";
	else
		return def;
}

int main() 
{ 
    int n = 7; 
    cout << areAllBitsSet_while(n) << endl; 
    cout << areAllBitsSet_while(n+1) << endl; 
    cout << areAllBitsSet_log(n) << endl; 
    cout << areAllBitsSet_log(n+1) << endl; 
    cout << areAllBitsSet_And(n) << endl; 
    cout << areAllBitsSet_And(n+1) << endl; 
    return 0; 
} 

