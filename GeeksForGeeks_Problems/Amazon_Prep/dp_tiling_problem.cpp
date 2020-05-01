// https://www.geeksforgeeks.org/tiling-problem/
// Similar : https://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/
// Input : 
// Output : 
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int countWays_rec(int n, int m)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	
	return countWays_rec(n-1, m) + countWays_rec(n-m, m);
}

int countWays_dp(int n, int m)
{
	int count[n+1];
	
	count[0] = 0;
	count[1] = 1;
	int i;
	
	for(i = 0; i <= n; i++)
	{
		if(i < m)
			count[i] = 1;
		else if(i > m)
			count[i] = count[i-1] + count[i-m];
		else
			count[i] = 2; // i == m
	}
	return count[n];
}

int main() 
{ 
    int n = 4, m = 2; 
    cout << "Number of ways = " << countWays_rec(n, m) << endl; 
    cout << "Number of ways = " << countWays_dp(n, m) << endl; 
    return 0; 
} 
