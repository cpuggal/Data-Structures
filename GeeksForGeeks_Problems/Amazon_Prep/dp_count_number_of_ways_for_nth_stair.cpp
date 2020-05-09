// https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
//

#include <iostream>
#include<bits/stdc++.h>

#define DEBUG		0	

using namespace std;

int countWays_rec(int num)
{
	if(num < 0)
		return 0;
		
	if(num == 0)
		return 1;
		
	else
		return countWays_rec(num - 1) + countWays_rec(num - 2);
}

int countWays_dp(int num)
{
	if(num <= 0)
		return 0;
	
	int tab[100] = {0};
	
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	int i;
	
	for(i = 3; i <= num; i++)
	{
		tab[i] = tab[i-1] + tab [i-2];
	}
	return tab[num];
}

int countWays_generic_dp(int num, int m)
{
	if(num <= 0)
		return 0;
	
	int tab[100] = {0};
	
	tab[0] = 1;
	tab[1] = 1;
	int i,j;
	
	for(i = 2; i <= num; i++)
	{
		for(j = 1; j <=m; j++)
		{
			tab[i] = tab[i] + tab[i-j];
		}
	}
	return tab[num];
}

int main () 
{ 
  int s = 4; 
  cout << "Number of ways " << countWays_rec(s) << endl; 
  cout << "Number of ways " << countWays_dp(s) << endl; 
  cout << "Number of ways " << countWays_generic_dp(s, 2) << endl; 
  cout << "Number of ways " << countWays_generic_dp(5, 3) << endl; 
  
  return 0; 
}

