// https://www.geeksforgeeks.org/check-if-a-number-can-be-expressed-as-xy-x-raised-to-power-y/
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPower(int n)
{
	int i = 0;
	int temp;
	for (i = 2; i <= sqrt(n); i++)
	{
		temp = i;
		
		while (temp <= n)
		{
			temp = temp * i;
			
			if (temp == n)
				return true;
		}
	}
	return false;
}

int main() 
{ 
    for (int i = 2; i < 100; i++) 
    {    if (isPower(i)) 
           cout << i << "  "; 
    }
    cout << endl;
    return 0; 
} 
