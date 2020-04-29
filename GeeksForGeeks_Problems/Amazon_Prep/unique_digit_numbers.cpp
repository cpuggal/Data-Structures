// https://www.geeksforgeeks.org/numbers-unique-distinct-digits/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

void printUnique(int left, int right)
{
	if (left > right)
		return;
	
	int i, temp;
	for(i = left; i<= right; i++)
	{
		temp = i;
		bool isVisited[10] = {false};
		while(temp)
		{
			if (isVisited[temp % 10] == true)
				break;
			else
				isVisited[temp % 10] = true;
			
			temp = temp/10;
		}
		if (!temp)
			cout << i << " ";
	}
	cout << endl;
}

int main() 
{ 
    int l = 1, r = 20; 
    printUnique(l, r); 
    printUnique(20, 30); 
    return 0; 
} 
