// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
//

#include <iostream>
#include <bits/stdc++.h>

#define	DEBUG	0

using namespace std;

int knapSack(int W, int w[], int val[], int n)
{
	if ((W == 0) || (n == 0))
		return 0;
	
	int take = val[n-1] + knapSack(W-w[n-1], w, val, n-1);
	int dont = knapSack(W, w, val, n-1);
	return max(take, dont);
}

int knapSack_dp(int W, int w[], int val[], int n)
{
	int DP[n+1][W+1];
	
	memset(DP, 0, sizeof(int)*(n+1)*(W+1));
	
	int i, j, dont_take, take;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= W; j++)
		{
			dont_take = DP[i-1][j];
			if(j >= w[i-1])
				take = val[i-1] + DP[i-1][j - w[i-1]]; //ith index in DP is i-1 in weights/val
			else
				take = 0;
			DP[i][j] = max(dont_take, take);
			if(DEBUG)
				cout << DP[i][j] << " ";
		}
		if(DEBUG)
			cout << endl;
	}
	return DP[n][W];
}

int main()  
{  
    int val[] = {60, 100, 120};  
    int wt[] = {10, 20, 30};  
    int W = 50;  
    int n = sizeof(val)/sizeof(val[0]);  
    cout << knapSack(W, wt, val, n) << endl;  
    cout << knapSack_dp(W, wt, val, n) << endl;  
    return 0;  
}
 
