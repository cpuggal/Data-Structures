// https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
// Input : 3
// Output : 4
// Input : 17
// Output : 35
//


#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG			0

int countSetBits(int n)
{
	if (n == 0)
		return 0;

	int i = 0, j = 0;
	int answer = 0;
	int k = 0;

	while((1 << i) < n) // bit by bit movement
	{
		for (j = 1; j <= n; j++) // all elements from 1 to n will be checked for bits.
		{
			if (j & (1 << i))
				answer ++;
		}
		i++;
	}
	return answer;
}

int main()
{
    int n = 17;
    cout << countSetBits(n) << endl;
    cout << countSetBits(3) << endl;
    return 0;
}
