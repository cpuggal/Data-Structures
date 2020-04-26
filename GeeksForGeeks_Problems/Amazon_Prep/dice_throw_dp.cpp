// https://www.geeksforgeeks.org/dice-throw-dp-30/
//
//
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG	0

int findWays(int m, int n, int sum)
{
	int Tab[n+1][sum+1];
	memset(Tab, 0, sizeof(Tab));

	int i, j, k;

	for(i = 0; i <= m && i <= sum; i++) //for one chance with all possible dice faces m, there is only 1 possibilty
		Tab[1][i] = 1;

	for(i = 2; i <= n; i++)
	{
		for(j = 1; j <= sum; j++)
		{
			for(k = 1; k <= m && k < j; k++)
			{
				Tab[i][j] += Tab[i-1][j-k];
			}
		}
	}
	if (DEBUG)
	{
		for (int i = 0; i <= n; i++)
	    {
	      for (int j = 0; j <= sum; j++)
	        cout << Tab[i][j] << "     ";
	      cout << endl;
	    }
	}
    return Tab[n][sum];
}

int main()
{
	cout << findWays(4, 2, 1) << endl;
    cout << findWays(2, 2, 3) << endl;
    cout << findWays(6, 3, 8) << endl;
    cout << findWays(4, 2, 5) << endl;
    cout << findWays(4, 3, 5) << endl;
    return 0;
}
